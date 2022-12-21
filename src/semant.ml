open Ast
open Unification
open Instantiation

module M = Map.Make(String)
module S = Set.Make(String)

(* Implementation of Algorithm W based on this description:
     https://jeremymikkola.com/posts/2018_03_25_understanding_algorithm_w.html
   (with the caveat that the given description for substitution
   composition is very likely slightly wrong; fixed in this code)
 *)

let rec check (expr : hExpr) (typEnv : typeEnvironm) : evalResult =
  match expr with
  | NoHint(x) ->
       check (Hint(x, nextTypVar last)) typEnv
(*---------------------------------------------------------------------------*)  
  | Hint(Var (s), t)             -> 
       (* Instantiation of forall types is done at this step;
          This also checks for referencing of undefined vars *)
       if M.mem s typEnv
       then
           let (tp, sub) = unification (instantiate (M.find s typEnv)) t in
           { tp    = tp;
             sexpr = (tp, SVar s);
             sub   = sub;
           }
       else raise (Failure("use of undefined variable " ^ s))
(*---------------------------------------------------------------------------*)  
  | Hint(ListLit(lst), t) ->
       if (List.length lst) = 0
       then 
         { tp = t;
           sexpr = (t, (SListLit []));
           sub = M.empty;
         }
       else
         let (typEnv, sub1, tacc, sacc) = List.fold_right 
                                            (fun e (typEnv, sub, acc, sacc) -> 
                                               let { tp = tp;
                                                     sexpr = sexpr;
                                                     sub = sub2; } = check e typEnv in
                                               let typEnv = applyte sub2 typEnv in
                                               let sub = compose sub sub2 in
                                               (typEnv, sub, tp :: acc, sexpr :: sacc)) 
                                            lst
                                            (typEnv, M.empty, [], []) in
         let (commontp, sub2) = List.fold_right 
                                  (fun tp (commontp, sub) ->
                                     let (tu, sub2) = unification tp commontp in
                                     let sub = compose sub sub2 in
                                     (tu, sub))
                                  tacc
                                  (nextTypVar last, M.empty) in
         let (tu, sub3) = unification t (ListTyp commontp) in
         let sub = compose (compose sub1 sub2) sub3 in

         { tp    = tu;
           sexpr = (tu, SListLit sacc);
           sub   = sub;
         }
  (*---------------------------------------------------------------------------*)  
  | Hint(Binop(b, e, f), t)     ->
         let (commonT, returnT) = (match b with
         | ADD -> (Concrete "Int", Concrete "Int")
         | FADD -> (Concrete "Float", Concrete "Float")
         | SUB -> (Concrete "Int", Concrete "Int")
         | FSUB -> (Concrete "Float", Concrete "Float")
         | MLT -> (Concrete "Int", Concrete "Int")
         | FMLT -> (Concrete "Float", Concrete "Float")
         | DIV -> (Concrete "Int", Concrete "Int")
         | FDIV -> (Concrete "Float", Concrete "Float")
         | MOD -> (Concrete "Int", Concrete "Int")
         | FMOD -> (Concrete "Float", Concrete "Float")
         | AND -> (Concrete "Bool", Concrete "Bool")
         | OR  -> (Concrete "Bool", Concrete "Bool")
         | EQ  -> (nextTypVar last, Concrete "Bool")
         | LT  -> (nextTypVar last, Concrete "Bool")
         | LTE -> (nextTypVar last, Concrete "Bool")
         | GT  -> (nextTypVar last, Concrete "Bool")
         | GTE -> (nextTypVar last, Concrete "Bool")) in
         let (returnT, subR) = unification returnT t in
         let typEnvNew = applyte subR typEnv in

         let { tp    = te;
               sexpr = se;
               sub   = sube; } = check e typEnvNew in
         let typEnvNew = applyte sube typEnvNew in
         let (tU, subU) = unification te commonT in
         let typEnvNew = applyte subU typEnvNew in
         let sub = compose (compose subR sube) subU in

         let { tp    = tf;
               sexpr = sf;
               sub   = subf; } = check f typEnvNew in
         let (tU, subU) = unification tf tU in
         let sub = compose (compose sub subf) subU in

         { tp    = returnT;
           sexpr = (returnT, SBinop(b, se, sf));
           sub   = sub;
         }
(*---------------------------------------------------------------------------*)  
  | Hint(LCons(e, f), t) ->
         let { tp = te;
               sexpr = se;
               sub = sube; } = check e typEnv in
         let { tp = tf;
               sexpr = sf;
               sub = subf; } = check f typEnv in
         let (tpl, subl) = unification (ListTyp te) tf in
         let (tph, subh) = unification tpl t in
         { tp = tph;
           sexpr = (te, SLCons(se, sf));
           sub = subh;
         }
(*---------------------------------------------------------------------------*)  
  | Hint(LLen(e), t) ->
         let { tp = te;
               sexpr = se;
               sub = sube; } = check e typEnv in
         let (returnT, subR) = unification (Concrete "Int") t in
         let (tpl, subl) = unification (ListTyp (nextTypVar last)) te in
         { tp = returnT;
           sexpr = (returnT, SLLen(se));
           sub = compose subR subl;
         }
(*---------------------------------------------------------------------------*)  
  | Hint(Unop(b, e), t)     ->
         let (commonT, returnT) = (match b with
         | NOT -> (Concrete "Bool", Concrete "Bool")) in
         let (returnT, subR) = unification returnT t in
         let typEnvNew = applyte subR typEnv in
          
         let { tp    = te;
               sexpr = se;
               sub   = sube; } = check e typEnvNew in
         let (tU, subU) = unification te commonT in
         let sub = compose (compose subR sube) subU in

         { tp    = returnT;
           sexpr = (returnT, SUnop(b, se));
           sub   = sub;
         }
(*---------------------------------------------------------------------------*)  
  | Hint(If(c, t, e), tp)     ->
         (* it is essential to NOT evaluate both branches prematurely;
            this can lead to infinite runs on branches that are actually
            never executed; for this reason, the two expressions within
            the if are wrapped in lambdas; when a branch is entered, that
            lambda is executed; this behaviour is sort-of thunk-like 
          *)
         let tp = ArrowTyp(nextTypVar last, tp) in
         let t = NoHint(Lambda (LVar "res", t)) in
         let e = NoHint(Lambda (LVar "res", e)) in
         let { tp    = tc;
               sexpr = sc;
               sub   = subc; } = check c typEnv in
         let typEnvNew = applyte subc typEnv in
         let (tU, subU) = unification tc (Concrete "Bool") in
         let typEnvNew = applyte subU typEnvNew in
         let sub = compose subc subU in
         let { tp    = tt;
               sexpr = st;
               sub   = subt; } = check t typEnvNew in
         let typEnvNew = applyte subt typEnvNew in
         let (tU, subU) = unification tt tp in
         let typEnvNew = applyte subU typEnvNew in
         let sub = compose (compose sub subt) subU in
         let { tp    = te;
               sexpr = se;
               sub   = sube; } = check e typEnvNew in
         let (tU, subU) = unification (apply sube tU) te in
         let sub = compose (compose sub sube) subU in

         let tp = 
             (match tU with
              | ArrowTyp(_, tp) -> tp
              | _ -> assert false)
         in
         { tp    = tp;
           sexpr = (tp, SIf(sc, st, se));
           sub   = sub;
         }
(*---------------------------------------------------------------------------*)  
  | Hint(UnitLit, t)          ->
         let (tp, sub) = unification Unit t in
         { tp    = tp;
           sexpr = (tp, SUnitLit);
           sub   = sub;
         }          
(*---------------------------------------------------------------------------*)  
  | Hint(IntLit (i), t)          ->
         let (tp, sub) = unification (Concrete "Int") t in
         { tp    = tp;
           sexpr = (tp, SIntLit i);
           sub   = sub;
         }          
(*---------------------------------------------------------------------------*)  
  | Hint(CharLit (i), t)          ->
         let (tp, sub) = unification (Concrete "Char") t in
         { tp    = tp;
           sexpr = (tp, SCharLit i);
           sub   = sub;
         }          
(*---------------------------------------------------------------------------*)  
  | Hint(BoolLit (b), t)         ->
         let (tp, sub) = unification (Concrete "Bool") t in
         { tp    = tp;
           sexpr = (tp, SBoolLit b);
           sub   = sub;
         }
(*---------------------------------------------------------------------------*)  
  | Hint(FloatLit (f), t)         ->
         let (tp, sub) = unification (Concrete "Float") t in
         { tp    = tp;
           sexpr = (tp, SFloatLit f);
           sub   = sub;
         }
(*---------------------------------------------------------------------------*)  
  | Hint(Lambda (LVar(v), e), tp) -> 
         let tv = nextTypVar last in
         let typEnvNew = M.add v (Scheme([], tv)) typEnv in

         let { tp    = bodyTyp; 
               sexpr = bsexpr; 
               sub   = sub1; } = check e typEnvNew in
         let argTyp = apply sub1 tv in

         let funcTyp, sub2 = unification (ArrowTyp(argTyp, bodyTyp)) tp in
         let sub = compose sub1 sub2 in

         { tp    = funcTyp;
           sexpr = (funcTyp, SLambda (LVar(v), bsexpr));
           sub   = sub;
         } 
(*---------------------------------------------------------------------------*)  
  | Hint(Call (f, arg), t)      -> 
         let retTyp = t in
         let { tp    = funcTypInit; 
               sexpr = fsexpr; 
               sub = sub1; } = check f typEnv in 
         let typEnvNew = applyte sub1 typEnv in
         let { tp    = argTyp; 
               sexpr = asexpr; 
               sub = sub2; } = check arg typEnvNew in
         let funcTypSub = apply sub2 funcTypInit in
         let funcTyp = ArrowTyp(argTyp, retTyp) in (* test 6 error? *)
         let _, sub3 = unification funcTypSub funcTyp in
         let sub = compose (compose sub1 sub2) sub3 in
         let tp = apply sub retTyp in 

         { tp    = tp;
           sexpr = (tp, SCall (fsexpr, asexpr));
           sub   = sub;
         }
(*---------------------------------------------------------------------------*)  
  | Hint(Let (Binding(LVar(v), e, false), f), t) ->
         (* non-recursive let-bindings *)

         (* let bindings cannot be treated as lambda abstractions if we
            want to obtain let polymorphism; for this reason, they are
            treated separately here; however, after the type inference
            and checking are complete, the C code treats the let as a
            regular lambda abstraction *)

         (* evaluate the assigned type, unify it with the type hint and
            finally generalize; it is important to unify before generalizing
            since type hints are monomorphic *)
         let { tp    = assnTyp; 
               sexpr = esexpr; 
               sub = sub1; } = check e typEnv in
         let typEnvNew = applyte sub1 typEnv in
         let (assnTypUni, sub2) = unification t assnTyp in
         let assnTypGen = generalize assnTypUni typEnvNew "" in

         (* add the generalized polymorphic type to the type environment
            and evaluate the resulting type *)
         let typEnvNew = M.add v assnTypGen typEnv in
         let sub = compose sub1 sub2 in
         let typEnvNew = applyte sub typEnvNew in
         let { tp    = funcTyp; 
               sexpr = fsexpr; 
               sub   = sub3; } = check f typEnvNew in
             
         { tp    = funcTyp;
           sexpr = (funcTyp, SLet (SBinding (LVar(v), esexpr, false), fsexpr));
           sub   = compose sub sub3;
         }
(*---------------------------------------------------------------------------*)  
  | Hint(Let (Binding(LVar(v), e, true), f), t) ->
        (* a let rec equal to a non-lambda expression cannot possibly
           refer to itself, so revert to non-recursive case *)
        let isLambda = 
          (match e with
            | NoHint(Lambda(_, _))  -> true
            | Hint(Lambda(_, _), _) -> true
            | _ -> false)
        in 
        if not isLambda
        then check (Hint(Let(Binding(LVar(v), e, false), f), t)) typEnv
        else
        (* recursive let-bindings *)

        (* use of the recursive let-binding must be monomorphic in its
           definition and can be polymorphic outside of its definition;
           apparently, this is a constraint imposed by HM inference.

           for recursive let-bindings, we cannot use the regular
           function application as in the non-recursive case - because
           the body of the function expects the function itself as an
           argument; for this reason, we need to first instantiate the
           function body, then make it refer to itself, then call the
           function application *)
        let vTyp = t in
        
        (* add the type hint for v to the type environment (or a new
           type variable in case no hint is given *)
        let typEnvNew = M.add v (Scheme([], vTyp)) typEnv in

        (* evaluate the assigned type, unify it with the potential type hint,
           then generalize the unified type; it is important to generalize
           AFTER the unification since type hints are monomorphic *)
        let { tp = assnTyp; 
              sexpr = esexpr; 
              sub = sub1; } = check e typEnvNew in
        let typEnvNew = applyte sub1 typEnv in
        let (vTypUni, sub2) = unification (apply sub1 vTyp) assnTyp in
        let vTypGen = generalize vTypUni typEnvNew v in
        
        (* add the unified polymorphic type for v to the map and
           apply the substitutions obtained during the previous process;
           finally determine the type of the resulting expression *)
        let typEnvNew = M.add v vTypGen typEnv in
        let sub = compose sub1 sub2 in
        let typEnvNew = applyte sub typEnvNew in
        let { tp    = retTyp; 
              sexpr = fsexpr; 
              sub = sub3; } = check f typEnvNew in
        { tp    = retTyp;
          sexpr = (retTyp, SLet (SBinding (LVar (v), esexpr, true), fsexpr));
          sub   = compose sub sub3;
        }
(*---------------------------------------------------------------------------*)  
  | Hint(Let (CBinding(lhs, rhs), f), t) ->
        let { tp    = rtp;
              sexpr = rexp;
              sub   = rsub; } = check rhs typEnv in
        let typEnvNew = List.fold_left 
                          (fun m (LVar v) -> M.add v (Scheme([], nextTypVar last)) m) 
                          typEnv 
                          lhs in   
        let { tp    = ftp;
              sexpr = fexp;
              sub   = fsub; } = check f typEnvNew in
        { tp    = ftp;
          sexpr = (ftp, SLet (SCBinding(lhs, rexp), fexp));
          sub   = compose rsub fsub;
        }
(*---------------------------------------------------------------------------*)  
  | Hint(Let (MBinding(lhs, rhs), f), t) ->
        let { tp    = rtp;
              sexpr = rexp;
              sub   = rsub; } = check rhs typEnv in
        let typEnvNew = List.fold_left 
                          (fun m (LVar v) -> M.add v (Scheme([], nextTypVar last)) m) 
                          typEnv 
                          lhs in   
        let { tp    = ftp;
              sexpr = fexp;
              sub   = fsub; } = check f typEnvNew in
        { tp    = ftp;
          sexpr = (ftp, SLet (SMBinding(lhs, rexp), fexp));
          sub   = compose rsub fsub;
        }
(*---------------------------------------------------------------------------*)  
   | Hint(Print(expr), t) ->
        let (tpUnit, sub1) = unification Unit t in
        let typEnvNew = applyte sub1 typEnv in
        let { tp = xtp;
              sexpr = xexp;
              sub = xsub; } = check expr typEnvNew in
        let (tp, sub2) = unification xtp (ListTyp (Concrete "Char")) in
        let sub = compose sub1 sub2 in

        { tp = tpUnit;
          sexpr = (tpUnit, SPrint(xexp));
          sub = sub;
        }
(*---------------------------------------------------------------------------*)  
   | Hint(Ord(expr), t) ->
        let (tpRet, sub1) = unification (Concrete "Int") t in
        let typEnvNew = applyte sub1 typEnv in
        let { tp = xtp;
              sexpr = xexp;
              sub = xsub; } = check expr typEnvNew in
        let (_, sub2) = unification xtp (Concrete "Char") in
        let sub = compose sub1 sub2 in

        { tp = tpRet;
          sexpr = (tpRet, SOrd(xexp));
          sub = sub;
        }
(*---------------------------------------------------------------------------*)  
   | Hint(Chr(expr), t) -> 
        let (tpRet, sub1) = unification (Concrete "Char") t in
        let typEnvNew = applyte sub1 typEnv in
        let { tp = xtp;
              sexpr = xexp;
              sub = xsub; } = check expr typEnvNew in
        let (_, sub2) = unification xtp (Concrete "Int") in
        let sub = compose sub1 sub2 in

        { tp = tpRet;
          sexpr = (tpRet, SChr(xexp));
          sub = sub;
        } 
(*---------------------------------------------------------------------------*)  
    | Hint(SItoFP(expr), t) ->       
        let (tpRet, sub1) = unification (Concrete "Float") t in
        let typEnvNew = applyte sub1 typEnv in
        let { tp = xtp;
              sexpr = xexp;
              sub = xsub; } = check expr typEnvNew in
        let (_, sub2) = unification xtp (Concrete "Int") in
        let sub = compose sub1 sub2 in
  
        { tp = tpRet;
          sexpr = (tpRet, SSItoFP(xexp));
          sub = sub;
        }
(*---------------------------------------------------------------------------*)  
    | Hint(FPtoSI(expr), t) -> 
        let (tpRet, sub1) = unification (Concrete "Int") t in
        let typEnvNew = applyte sub1 typEnv in
        let { tp = xtp;
              sexpr = xexp;
              sub = xsub; } = check expr typEnvNew in
        let (_, sub2) = unification xtp (Concrete "Float") in
        let sub = compose sub1 sub2 in

        { tp = tpRet;
          sexpr = (tpRet, SFPtoSI(xexp));
          sub = sub;
        }
