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
          (* Instantiation of forall types is done at this step;
             This also checks for referencing of undefined vars *)
          if M.mem s typEnv
          then
              let tp = instantiate (M.find s typEnv) in
              { tp    = tp;
                sexpr = (tp, SVar s); 
                sub   = M.empty;
              }
          else raise (Failure("use of undefined variable " ^ s))
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
  | NoHint(Binop(b, e, f))      -> 
          let (commonT, returnT) = (match b with
          | ADD -> (Concrete "Int", Concrete "Int")
          | SUB -> (Concrete "Int", Concrete "Int")
          | MLT -> (Concrete "Int", Concrete "Int")
          | DIV -> (Concrete "Int", Concrete "Int")
          | MOD -> (Concrete "Int", Concrete "Int")
          | AND -> (Concrete "Bool", Concrete "Bool")
          | OR  -> (Concrete "Bool", Concrete "Bool")
          | EQ  -> (nextTypVar last, Concrete "Bool")) in

          let { tp    = te;
                sexpr = se;
                sub   = sube; } = check e typEnv in
          let typEnvNew = applyte sube typEnv in
          let (tU, subU) = unification te commonT in
          let typEnvNew = applyte subU typEnvNew in
          let sub = compose sube subU in

          let { tp    = tf;
                sexpr = sf;
                sub   = subf; } = check f typEnvNew in
          let typEnvNew = applyte subf typEnvNew in
          let (tU, subU) = unification tf tU in
          let sub = compose (compose sub subf) subU in

          { tp    = returnT;
            sexpr = (returnT, SBinop(b, se, sf));
            sub   = sub;
          }
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
          let typEnvNew = applyte subf typEnvNew in
          let (tU, subU) = unification tf tU in
          let sub = compose (compose sub subf) subU in

          { tp    = returnT;
            sexpr = (returnT, SBinop(b, se, sf));
            sub   = sub;
          }
(*---------------------------------------------------------------------------*)  
  | NoHint(Unop(b, e))      -> 
          let (commonT, returnT) = (match b with
          | NOT -> (Concrete "Bool", Concrete "Bool")) in
          
          let { tp    = te;
                sexpr = se;
                sub   = sube; } = check e typEnv in
          let typEnvNew = applyte sube typEnv in
          let (tU, subU) = unification te commonT in
          let typEnvNew = applyte subU typEnvNew in
          let sub = compose sube subU in

          { tp    = returnT;
            sexpr = (returnT, SUnop(b, se));
            sub   = sub;
          }
  | Hint(Unop(b, e), t)     ->
          let (commonT, returnT) = (match b with
          | NOT -> (Concrete "Bool", Concrete "Bool")) in
          let (returnT, subR) = unification returnT t in
          let typEnvNew = applyte subR typEnv in
          
          let { tp    = te;
                sexpr = se;
                sub   = sube; } = check e typEnvNew in
          let typEnvNew = applyte sube typEnvNew in
          let (tU, subU) = unification te commonT in
          let typEnvNew = applyte subU typEnvNew in
          let sub = compose (compose subR sube) subU in

          { tp    = returnT;
            sexpr = (returnT, SUnop(b, se));
            sub   = sub;
          }
(*---------------------------------------------------------------------------*)  
  | NoHint(PIf(c, t, e))      -> 
          let tp = nextTypVar last in
          let { tp    = _;
                sexpr = sc;
                sub   = _; } = check c typEnv in
          let { tp    = _;
                sexpr = st;
                sub   = _; } = check t typEnv in
          let { tp    = _;
                sexpr = se;
                sub   = _; } = check e typEnv in
          { tp    = tp;
            sexpr = (tp, SPIf(sc, st, se));
            sub   = M.empty;
          }
  | Hint(PIf(c, t, e), tp)     ->
          let tp = nextTypVar last in
          let { tp    = _;
                sexpr = sc;
                sub   = _; } = check c typEnv in
          let { tp    = _;
                sexpr = st;
                sub   = _; } = check t typEnv in
          let { tp    = _;
                sexpr = se;
                sub   = _; } = check e typEnv in
          { tp    = tp;
            sexpr = (tp, SPIf(sc, st, se));
            sub   = M.empty;
          }
(*---------------------------------------------------------------------------*)  
  | NoHint(IntLit (i))           ->
          let tp = Concrete "Int" in
          { tp    = tp;
            sexpr = (tp, SIntLit i);
            sub   = M.empty;
          }
  | Hint(IntLit (i), t)          ->
          let (tp, sub) = unification (Concrete "Int") t in
          { tp    = tp;
            sexpr = (tp, SIntLit i);
            sub   = sub;
          }          
(*---------------------------------------------------------------------------*)  
  | NoHint(BoolLit (b))          ->
          let tp = Concrete "Bool" in
          { tp    = tp;
            sexpr = (tp, SBoolLit b);
            sub   = M.empty;
          }
  | Hint(BoolLit (b), t)         ->
          let (tp, sub) = unification (Concrete "Bool") t in
          { tp    = tp;
            sexpr = (tp, SBoolLit b);
            sub   = sub;
          }
(*---------------------------------------------------------------------------*)  
  | NoHint(Lambda (LVar(v), e)) -> 
          let tv = nextTypVar last in
          let typEnvNew = M.add v (Scheme([], tv)) typEnv in

          let { tp    = bodyTyp; 
                sexpr = bsexpr; 
                sub   = sub; } = check e typEnvNew in
          let argTyp = apply sub tv in

          let tp = ArrowTyp(argTyp, bodyTyp) in
          { tp    = tp;
            sexpr = (tp, SLambda (LVar(v), bsexpr));
            sub   = sub;
          }
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
          let retTyp = nextTypVar last in
          let { tp    = funcTypInit; 
                sexpr = fsexpr; 
                sub   = sub1; } = check f typEnv in 
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
  | NoHint(If (c, t, e))        -> 
          (* treat if-statements like a ternary operator/function with
             type forall a. bool -> a -> a -> a; this removes the need
             for any additional typing logic and relies on the correctness 
             of function application 

             it is essential to NOT evaluate both branches prematurely;
             this can lead to infinite runs on branches that are actually
             never executed; for this reason, the two expressions within
             the if are wrapped in lambdas; when a branch is entered, that
             lambda is executed; this behaviour is sort-of thunk-like
           *)
            
          check (NoHint(Call(NoHint(Call(NoHint(Call(NoHint(Var "operator_if"), c)), 
                                  NoHint(Lambda (LVar "res", t)))), 
                                  NoHint(Lambda (LVar "res", e))))) typEnv
  | Hint(If (c, t, e), tp)        -> 
          check (Hint(Call(NoHint(Call(NoHint(Call(NoHint(Var "operator_if"), c)), 
                                 NoHint(Lambda (LVar "res", t)))), 
                                 NoHint(Lambda (LVar "res", e))), tp)) typEnv  
(*---------------------------------------------------------------------------*)  
  | NoHint(Let (Binding(LVar(v), e, false), f)) ->
          (* non-recursive let-bindings *)

          (* let bindings cannot be treated as lambda abstractions if we
             want to obtain let polymorphism; for this reason, they are
             treated separately here; however, after the type inference
             and checking are complete, the C code treats the let as a
             regular lambda abstraction *)

          (* evaluate the assigned type, generalize it, insert it back
             into the type environment together with the resulting
             substitutions, then evaluate the resulting type *)
          let { tp    = t1; 
                sexpr = esexpr; 
                sub = sub1; } = check e typEnv in
          let typEnvNew = applyte sub1 typEnv in
          let s1 = generalize t1 typEnvNew "" in
          let typEnvNew = M.add v s1 typEnv in
          let typEnvNew = applyte sub1 typEnvNew in
          let { tp    = funcTyp; 
                sexpr = fsexpr; 
                sub = sub2; } = check f typEnvNew in

          { tp    = funcTyp;
            sexpr = (funcTyp, SLet (SBinding (LVar(v), esexpr, false), fsexpr));
            sub   = compose sub1 sub2;
          }
  | Hint(Let (Binding(LVar(v), e, false), f), t) ->
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
  | NoHint(Let (Binding(LVar(v), e, _), f))  ->
        (* a let rec equal to a non-lambda expression cannot possibly
           refer to itself, so revert to non-recursive case *)
        let isLambda = 
          (match e with
            | NoHint(Lambda(_, _))  -> true
            | Hint(Lambda(_, _), _) -> true
            | _ -> false)
        in 
        if not isLambda
        then check (NoHint(Let(Binding(LVar(v), e, false), f))) typEnv
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

        let vTyp = nextTypVar last in
        
        (* add the type hint for v to the type environment (or a new
           type variable in case no hint is given *)
        let typEnvNew = M.add v (Scheme([], vTyp)) typEnv in

        (* evaluate the assigned type, unify it with the potential type hint,
           then generalize the unified type; it is important to generalize
           AFTER the unification since type hints are monomorphic *)
        let { tp    = assnTyp; 
              sexpr = esexpr; 
              sub   = sub1; } = check e typEnvNew in
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
              sub   = sub3; } = check f typEnvNew in

        (* check that the resulting polymorphic type of v is an arrow type
           and discard the rec qualifier applied to non-arrow types; this
           is a useful shortcut since non-arrow types are not instance of
           some class but arbitrary pointers (e.g. Int/Bool), and making them
           recursive would require a more involved translation process *)
        let Scheme(_, arrowTyp) = vTypGen in
        let _ = match arrowTyp with
                  | ArrowTyp(_, _) -> ()
                  | _ -> raise(Failure("rec qualifier can only be used on functions"))
        in
        
        { tp    = retTyp;
          sexpr = (retTyp, SLet (SBinding (LVar(v), esexpr, true), fsexpr));
          sub   = compose sub sub3;
        }

  | Hint(Let (Binding(LVar(v), e, _), f), t) ->
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

        (* check that the resulting polymorphic type of v is an arrow type
           and discard the rec qualifier applied to non-arrow types; this
           is a useful shortcut since non-arrow types are not instance of
           some class but arbitrary pointers (e.g. Int/Bool), and making them
           recursive would require a more involved translation process *)
        let Scheme(_, arrowTyp) = vTypGen in
        let _ = match arrowTyp with
                  | ArrowTyp(_, _) -> ()
                  | _ -> raise(Failure("rec qualifier can only be used on functions"))
        in
        
        { tp    = retTyp;
          sexpr = (retTyp, SLet (SBinding (LVar (v), esexpr, true), fsexpr));
          sub   = compose sub sub3;
        }

  | _ -> raise(Failure("Semantic checking for pattern matching not implemented yet"))
