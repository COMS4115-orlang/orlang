open Ast
open Unification
open Instantiation
open Cpp
module M = Map.Make(String)
module S = Set.Make(String)

let classes = ref ""

(* Implementation of Algorithm W based on this description:
     https://jeremymikkola.com/posts/2018_03_25_understanding_algorithm_w.html
   (with the caveat that the given description for substitution
   composition is very likely slightly wrong; fixed in this code)
 *)

let find x ys = 
    let rec helper x index = function
    |  []     -> raise(Failure("impossible"))
    | y :: ys -> if x = y then index
                          else helper x (index + 1) ys
    in helper x 0 ys

let rec check (expr : hExpr) (typEnv : typeEnvironm) : evalResult =
  match expr with
  | NoHint(Var (s))             -> 
          (* Instantiation of forall types is done at this step;
             This also checks for referencing of undefined vars *)
          if M.mem s typEnv
          then
              let tp = instantiate (M.find s typEnv) in
              let ordered = (M.fold (fun k _ acc -> k :: acc) typEnv []) in
              let index = find s ordered in
              { code  = "(*((void**) env + 1 + " ^ string_of_int index ^ "))";
                tp    = tp;
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
              { code  = "env->" ^ s;
                tp    = tp;
                sexpr = (tp, SVar s);
                sub   = sub;
              }
          else raise (Failure("use of undefined variable " ^ s))
(*---------------------------------------------------------------------------*)  
  | NoHint(IntLit (i))           ->
          let tp = Concrete "Int" in
          { code  = "((void*) " ^ string_of_int i ^ ")";
            tp    = tp;
            sexpr = (tp, SIntLit i);
            sub   = M.empty;
          }
  | Hint(IntLit (i), t)          ->
          let (tp, sub) = unification (Concrete "Int") t in
          { code = "((void*) " ^ string_of_int i ^ ")";
            tp   = tp;
            sexpr = (tp, SIntLit i);
            sub  = sub;
          }          
(*---------------------------------------------------------------------------*)  
  | NoHint(BoolLit (b))          ->
          let tp = Concrete "Bool" in
          { code = "((void*) " ^ string_of_int b ^ ")";
            tp   = tp;
            sexpr = (tp, SBoolLit b);
            sub  = M.empty;
          }
  | Hint(BoolLit (b), t)         ->
          let (tp, sub) = unification (Concrete "Bool") t in
          { code = "((void*) " ^ string_of_int b ^ ")";
            tp   = tp;
            sexpr = (tp, SBoolLit b);
            sub  = sub;
          }
(*---------------------------------------------------------------------------*)  
  | NoHint(Lambda (LVar(v), e)) -> 
          let tv = nextTypVar last in
          let typEnvNew = M.add v (Scheme([], tv)) typEnv in

          let { code = code; tp = bodyTyp; sexpr = bsexpr; sub = sub; } = check e typEnvNew in
          let argTyp = apply sub tv in

          let name = nextEntry lastClass in
          let tp = ArrowTyp(argTyp, bodyTyp) in
          (
              (* generate the code for the class/call/constructor of this lambda *)
              classes := !classes ^ 
                         cppfunction name v code typEnv;
              { code = cppfunctioninst name v typEnv;
                tp   = tp;
                sexpr = (tp, SLambda (LVar(v), bsexpr));
                sub  = sub;
              }
          )
  | Hint(Lambda (LVar(v), e), tp) -> 
          let tv = nextTypVar last in
          let typEnvNew = M.add v (Scheme([], tv)) typEnv in

          let { code = code; tp = bodyTyp; sexpr = bsexpr; sub = sub1; } = check e typEnvNew in
          let argTyp = apply sub1 tv in

          let funcTyp, sub2 = unification (ArrowTyp(argTyp, bodyTyp)) tp in
          let sub = compose sub1 sub2 in

          let name = nextEntry lastClass in
          (
              (* generate the code for the class/call/constructor of this lambda *)
              classes := !classes ^ 
                         cppfunction name v code typEnv;
              { code = cppfunctioninst name v typEnv;
                tp   = funcTyp;
                sexpr = (funcTyp, SLambda (LVar(v), bsexpr));
                sub  = sub;
              }
          )
(*---------------------------------------------------------------------------*)  
  | NoHint(Call (f, arg))       -> 
          let retTyp = nextTypVar last in
          let { code = codef; tp = funcTypInit; sexpr = fsexpr; sub = sub1; } = check f typEnv in 
          let typEnvNew = applyte sub1 typEnv in
          let { code = codearg; tp = argTyp; sexpr = asexpr; sub = sub2; } = check arg typEnvNew in
          let funcTypSub = apply sub2 funcTypInit in
          let funcTyp = ArrowTyp(argTyp, retTyp) in
          let _, sub3 = unification funcTypSub funcTyp in
          let sub = compose (compose sub1 sub2) sub3 in
          let tp = apply sub retTyp in

          { code = "apply(" ^ codef ^ ", " ^ codearg ^ ")";
            tp   = tp;
            sexpr = (tp, SCall (fsexpr, asexpr));
            sub  = sub;
          }
  | Hint(Call (f, arg), t)      -> 
          let retTyp = t in
          let { code = codef; tp = funcTypInit; sexpr = fsexpr; sub = sub1; } = check f typEnv in 
          let typEnvNew = applyte sub1 typEnv in
          let { code = codearg; tp = argTyp; sexpr = asexpr; sub = sub2; } = check arg typEnvNew in
          let funcTypSub = apply sub2 funcTypInit in
          let funcTyp = ArrowTyp(argTyp, retTyp) in
          let _, sub3 = unification funcTypSub funcTyp in
          let sub = compose (compose sub1 sub2) sub3 in
          let tp = apply sub retTyp in 

          { code = "apply(" ^ codef ^ ", " ^ codearg ^ ")";
            tp   = tp;
            sexpr = (tp, SCall (fsexpr, asexpr));
            sub  = sub;
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
          let { code = codee; tp = t1; sexpr = esexpr; sub = sub1; } = check e typEnv in
          let typEnvNew = applyte sub1 typEnv in
          let s1 = generalize t1 typEnvNew "" in
          let typEnvNew = M.add v s1 typEnv in
          let typEnvNew = applyte sub1 typEnvNew in
          let { code = codef; tp = funcTyp; sexpr = fsexpr; sub = sub2; } = check f typEnvNew in
          let name = nextEntry lastClass in
          (
              (* C code is equivalent to lambda and call *)
              classes := !classes ^ 
                         cppfunction name v codef typEnv;
              { code = "apply(" ^ cppfunctioninst name v typEnv ^ ", " ^ codee ^ ")";
                tp = funcTyp;
                sexpr = (funcTyp, SLet (SBinding (LVar(v), esexpr, false), fsexpr));
                sub = compose sub1 sub2;
              }
          )
  | Hint(Let (Binding(LVar(v), e, false), f), t) ->
          (* evaluate the assigned type, unify it with the type hint and
             finally generalize; it is important to unify before generalizing
             since type hints are monomorphic *)
          let { code = codee; tp = assnTyp; sexpr = esexpr; sub = sub1; } = check e typEnv in
          let typEnvNew = applyte sub1 typEnv in
          let (assnTypUni, sub2) = unification t assnTyp in
          let assnTypGen = generalize assnTypUni typEnvNew "" in

          (* add the generalized polymorphic type to the type environment
             and evaluate the resulting type *)
          let typEnvNew = M.add v assnTypGen typEnv in
          let sub = compose sub1 sub2 in
          let typEnvNew = applyte sub typEnvNew in
          let { code = codef; tp = funcTyp; sexpr = fsexpr; sub = sub3; } = check f typEnvNew in

          let name = nextEntry lastClass in
          (
              classes := !classes ^ 
                         cppfunction name v codef typEnv;
              { code = "apply(" ^ cppfunctioninst name v typEnv ^ ", " ^ codee ^ ")";
                tp = funcTyp;
                sexpr = (funcTyp, SLet (SBinding (LVar(v), esexpr, false), fsexpr));
                sub = compose sub sub3;
              }
          )
(*---------------------------------------------------------------------------*)  
  | NoHint(Let (Binding(LVar(v), e, _), f))  ->
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
        let { code = codee; tp = assnTyp; sexpr = esexpr; sub = sub1; } = check e typEnvNew in
        let typEnvNew = applyte sub1 typEnv in
        let (vTypUni, sub2) = unification (apply sub1 vTyp) assnTyp in
        let vTypGen = generalize vTypUni typEnvNew v in
        
        (* add the unified polymorphic type for v to the map and
           apply the substitutions obtained during the previous process;
           finally determine the type of the resulting expression *)
        let typEnvNew = M.add v vTypGen typEnv in
        let sub = compose sub1 sub2 in
        let typEnvNew = applyte sub typEnvNew in
        let { code = codef; tp = retTyp; sexpr = fsexpr; sub = sub3; } = check f typEnvNew in

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
        
        (* special code generation for recursive let-bindings *)
        let name = nextEntry lastClass in
        let capture = (remove "main" 
                      (remove v 
                      (M.fold (fun k _ acc -> k :: acc) typEnv []))) in
        let acapture = sep ", env->" capture in
        let func = cppfunctioninst name v typEnv in
        (
            (* C code is equivalent to lambda and call *)
            classes := !classes ^ 
                       cppfunction name v codef typEnv ^
                       fix name v typEnv codee;
            { code = mangleApp name ^ "(" ^ func ^ ", env->" ^ acapture ^ ")";
              tp = retTyp;
              sexpr = (retTyp, SLet (SBinding (LVar(v), esexpr, true), fsexpr));
              sub = compose sub sub3;
            }
        )

  | Hint(Let (Binding(LVar(v), e, _), f), t) ->
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
        let { code = codee; tp = assnTyp; sexpr = esexpr; sub = sub1; } = check e typEnvNew in
        let typEnvNew = applyte sub1 typEnv in
        let (vTypUni, sub2) = unification (apply sub1 vTyp) assnTyp in
        let vTypGen = generalize vTypUni typEnvNew v in
        
        (* add the unified polymorphic type for v to the map and
           apply the substitutions obtained during the previous process;
           finally determine the type of the resulting expression *)
        let typEnvNew = M.add v vTypGen typEnv in
        let sub = compose sub1 sub2 in
        let typEnvNew = applyte sub typEnvNew in
        let { code = codef; tp = retTyp; sexpr = fsexpr; sub = sub3; } = check f typEnvNew in

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
        
        (* special code generation for recursive let-bindings *)
        let name = nextEntry lastClass in
        let capture = (remove "main" 
                      (remove v 
                      (M.fold (fun k _ acc -> k :: acc) typEnv []))) in
        let acapture = sep ", env->" capture in
        let func = cppfunctioninst name v typEnv in
        (
            (* C code is equivalent to lambda and call *)
            classes := !classes ^ 
                       cppfunction name v codef typEnv ^
                       fix name v typEnv codee;
            { code = mangleApp name ^ "(" ^ func ^ ", env->" ^ acapture ^ ")";
              tp = retTyp;
              sexpr = (retTyp, SLet (SBinding (LVar (v), esexpr, true), fsexpr));
              sub = compose sub sub3;
            }
        )

  | _ -> raise(Failure("Semantic checking for pattern matching not implemented yet"))
