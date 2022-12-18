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
  | NoHint(Var (s))             -> 
          check (Hint(Var(s), nextTypVar last)) typEnv
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
  | NoHint(ListLit(lst)) ->
          check (Hint(ListLit(lst), nextTypVar last)) typEnv 
  | Hint(ListLit(lst), t) ->
          if (List.length lst) = 0
          then raise (Failure("Empty list not supported"))
          else
            let rec checkHomogeneous tpList =
                (match tpList with
                  | x::y::xs  -> (x = y) && checkHomogeneous (y::xs)  
                  | _         -> true)
            in
            let checkedList = List.map (fun e -> check e typEnv) lst in
            if checkHomogeneous (List.map (fun c -> c.tp) checkedList)
            then
                let checkedElem = List.hd checkedList in
                let (lstTyp, lstSub)  = unification (ListTyp checkedElem.tp) t in
                let sexprList = List.map (fun x -> x.sexpr) checkedList in
                { tp    = lstTyp;
                  sexpr = (lstTyp, SListLit sexprList);
                  sub   = lstSub;
                }
            else raise (Failure("List type is not homogeneous"))
  (*---------------------------------------------------------------------------*)  
  | NoHint(Binop(b, e, f))      -> 
          check (Hint(Binop(b, e, f), nextTypVar last)) typEnv
  | Hint(Binop(b, e, f), t)     ->
          let (commonT, returnT) = (match b with
          | ADD -> (Concrete "Int", Concrete "Int")
          | SUB -> (Concrete "Int", Concrete "Int")
          | MLT -> (Concrete "Int", Concrete "Int")
          | DIV -> (Concrete "Int", Concrete "Int")
          | MOD -> (Concrete "Int", Concrete "Int")
          | AND -> (Concrete "Bool", Concrete "Bool")
          | OR  -> (Concrete "Bool", Concrete "Bool")
          | EQ  -> (nextTypVar last, Concrete "Bool")) in
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
  | NoHint(LCons(e, f)) ->
          check (Hint(LCons(e, f), nextTypVar last)) typEnv
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
  | NoHint(Unop(b, e))      -> 
          check (Hint(Unop(b, e), nextTypVar last)) typEnv
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
  | NoHint(If(c, t, e))      -> 
          check (Hint(If(c, t, e), nextTypVar last)) typEnv
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
  | NoHint(IntLit (i))           ->
          check (Hint(IntLit(i), nextTypVar last)) typEnv
  | Hint(IntLit (i), t)          ->
          let (tp, sub) = unification (Concrete "Int") t in
          { tp    = tp;
            sexpr = (tp, SIntLit i);
            sub   = sub;
          }          
(*---------------------------------------------------------------------------*)  
  | NoHint(BoolLit (b))          ->
          check (Hint(BoolLit(b), nextTypVar last)) typEnv
  | Hint(BoolLit (b), t)         ->
          let (tp, sub) = unification (Concrete "Bool") t in
          { tp    = tp;
            sexpr = (tp, SBoolLit b);
            sub   = sub;
          }
(*---------------------------------------------------------------------------*)  
  | NoHint(Lambda (LVar(v), e)) -> 
          check (Hint(Lambda (LVar(v), e), nextTypVar last)) typEnv
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
  | NoHint(Call (f, arg))       -> 
          check (Hint(Call (f, arg), nextTypVar last)) typEnv
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
          let funcTyp = ArrowTyp(argTyp, retTyp) in
          let _, sub3 = unification funcTypSub funcTyp in
          let sub = compose (compose sub1 sub2) sub3 in
          let tp = apply sub retTyp in 

          { tp    = tp;
            sexpr = (tp, SCall (fsexpr, asexpr));
            sub   = sub;
          }
(*---------------------------------------------------------------------------*)  
  | NoHint(Let (Binding(LVar(v), e, false), f)) ->
          check (Hint(Let (Binding(LVar(v), e, false), f), nextTypVar last)) typEnv
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
  | NoHint(Let (Binding(LVar(v), e, true), f))  ->
        check (Hint(Let (Binding(LVar(v), e, true), f), nextTypVar last)) typEnv
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
  | NoHint(Let (CBinding(lhs, rhs), f)) -> 
        check (Hint(Let (CBinding(lhs, rhs), f), nextTypVar last)) typEnv
  | Hint(Let (CBinding(lhs, rhs), f), t) ->
        let { tp    = rtp;
              sexpr = rexp;
              sub   = rsub; } = check rhs typEnv in
        let typEnvNew = List.fold_left (fun m (LVar v) -> M.add v (Scheme([], nextTypVar last)) m) typEnv lhs in   
        let { tp    = ftp;
              sexpr = fexp;
              sub   = fsub; } = check f typEnvNew in
        { tp    = ftp;
          sexpr = (ftp, SLet (SCBinding(lhs, rexp), fexp));
          sub   = compose rsub fsub;
        }
(*---------------------------------------------------------------------------*)  
  | NoHint(Let (MBinding(lhs, rhs), f)) -> 
        check (Hint(Let (MBinding(lhs, rhs), f), nextTypVar last)) typEnv
  | Hint(Let (MBinding(lhs, rhs), f), t) ->
        let { tp    = rtp;
              sexpr = rexp;
              sub   = rsub; } = check rhs typEnv in
        let typEnvNew = List.fold_left (fun m (LVar v) -> M.add v (Scheme([], nextTypVar last)) m) typEnv lhs in   
        let { tp    = ftp;
              sexpr = fexp;
              sub   = fsub; } = check f typEnvNew in
        { tp    = ftp;
          sexpr = (ftp, SLet (SMBinding(lhs, rexp), fexp));
          sub   = compose rsub fsub;
        }
(*---------------------------------------------------------------------------*)  
 | _ -> raise(Failure("Semantic checking for pattern matching not implemented yet"))
