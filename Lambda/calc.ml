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

let rec eval (expr : hExpr) (typEnv : typeEnvironm) : evalResult =
  match expr with
  | NoHint(Var (s))             -> 
          (* Instantiation of forall types is done at this step;
             This also checks for referencing of undefined vars *)
          if M.mem s typEnv
          then 
              { code = "env->" ^ (checkVar s);
                tp   = instantiate (M.find s typEnv);
                sub  = M.empty;
              }
          else raise (Failure("use of undefined variable " ^ s))
  | Hint(Var (s), t)             -> 
          (* Instantiation of forall types is done at this step;
             This also checks for referencing of undefined vars *)
          if M.mem s typEnv
          then
              let (tp, sub) = unification (instantiate (M.find s typEnv)) t in
              { code = "env->" ^ (checkVar s);
                tp   = tp;
                sub  = sub;
              }
          else raise (Failure("use of undefined variable " ^ s))
(*---------------------------------------------------------------------------*)  
  | NoHint(IntLit (i))           -> 
          { code = "((void*) " ^ string_of_int i ^ ")";
            tp   = Concrete "Int";
            sub  = M.empty;
          }
  | Hint(IntLit (i), t)          ->
          let (tp, sub) = unification (Concrete "Int") t in
          { code = "((void*) " ^ string_of_int i ^ ")";
            tp   = tp;
            sub  = sub;
          }          
(*---------------------------------------------------------------------------*)  
  | NoHint(BoolLit (b))          -> 
          { code = "((void*) " ^ string_of_int b ^ ")";
            tp   = Concrete "Bool";
            sub  = M.empty;
          }
  | Hint(BoolLit (b), t)         ->
          let (tp, sub) = unification (Concrete "Bool") t in
          { code = "((void*) " ^ string_of_int b ^ ")";
            tp   = tp;
            sub  = sub;
          }
(*---------------------------------------------------------------------------*)  
  | NoHint(Lambda (LVar(v), e)) -> 
          let tv = nextTypVar last in
          let typEnvNew = M.add v (Scheme([], tv)) typEnv in

          let { code = code; tp = bodyTyp; sub = sub; } = eval e typEnvNew in
          let argTyp = apply sub tv in

          let name = nextEntry lastClass in
          (
              (* generate the code for the class/call/constructor of this lambda *)
              classes := !classes ^ 
                         cppfunction name v code typEnv;
              { code = cppfunctioninst name v typEnv;
                tp   = ArrowTyp(argTyp, bodyTyp);
                sub  = sub;
              }
          )
  | Hint(Lambda (LVar(v), e), tp) -> 
          let tv = nextTypVar last in
          let typEnvNew = M.add v (Scheme([], tv)) typEnv in

          let { code = code; tp = bodyTyp; sub = sub1; } = eval e typEnvNew in
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
                sub  = sub;
              }
          )
(*---------------------------------------------------------------------------*)  
  | NoHint(Call (f, arg))       -> 
          let retTyp = nextTypVar last in
          let { code = codef; tp = funcTypInit; sub = sub1; } = eval f typEnv in 
          let typEnvNew = applyte sub1 typEnv in
          let { code = codearg; tp = argTyp; sub = sub2; } = eval arg typEnvNew in
          let funcTypSub = apply sub2 funcTypInit in
          let funcTyp = ArrowTyp(argTyp, retTyp) in
          let _, sub3 = unification funcTypSub funcTyp in
          let sub = compose (compose sub1 sub2) sub3 in

          { code = "apply(" ^ codef ^ ", " ^ codearg ^ ")";
            tp   = apply sub retTyp;
            sub  = sub;
          }
  | Hint(Call (f, arg), t)      -> 
          let retTyp = t in
          let { code = codef; tp = funcTypInit; sub = sub1; } = eval f typEnv in 
          let typEnvNew = applyte sub1 typEnv in
          let { code = codearg; tp = argTyp; sub = sub2; } = eval arg typEnvNew in
          let funcTypSub = apply sub2 funcTypInit in
          let funcTyp = ArrowTyp(argTyp, retTyp) in
          let _, sub3 = unification funcTypSub funcTyp in
          let sub = compose (compose sub1 sub2) sub3 in

          { code = "apply(" ^ codef ^ ", " ^ codearg ^ ")";
            tp   = apply sub retTyp;
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
            
          eval (NoHint(Call(NoHint(Call(NoHint(Call(NoHint(Var "operator_if"), c)), 
                                  NoHint(Lambda (LVar "res", t)))), 
                                  NoHint(Lambda (LVar "res", e))))) typEnv
  | Hint(If (c, t, e), tp)        -> 
          eval (Hint(Call(NoHint(Call(NoHint(Call(NoHint(Var "operator_if"), c)), 
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
          let { code = codee; tp = t1; sub = sub1; } = eval e typEnv in
          let typEnvNew = applyte sub1 typEnv in
          let s1 = generalize t1 typEnvNew "" in
          let typEnvNew = M.add v s1 typEnv in
          let typEnvNew = applyte sub1 typEnvNew in
          let { code = codef; tp = funcTyp; sub = sub2; } = eval f typEnvNew in
          let name = nextEntry lastClass in
          (
              (* C code is equivalent to lambda and call *)
              classes := !classes ^ 
                         cppfunction name v codef typEnv;
              { code = "apply(" ^ cppfunctioninst name v typEnv ^ ", " ^ codee ^ ")";
                tp = funcTyp;
                sub = compose sub1 sub2;
              }
          )
  | Hint(Let (Binding(LVar(v), e, false), f), t) ->
          (* evaluate the assigned type, unify it with the type hint and
             finally generalize; it is important to unify before generalizing
             since type hints are monomorphic *)
          let { code = codee; tp = assnTyp; sub = sub1; } = eval e typEnv in
          let typEnvNew = applyte sub1 typEnv in
          let (assnTypUni, sub2) = unification t assnTyp in
          let assnTypGen = generalize assnTypUni typEnvNew "" in

          (* add the generalized polymorphic type to the type environment
             and evaluate the resulting type *)
          let typEnvNew = M.add v assnTypGen typEnv in
          let sub = compose sub1 sub2 in
          let typEnvNew = applyte sub typEnvNew in
          let { code = codef; tp = funcTyp; sub = sub3; } = eval f typEnvNew in

          let name = nextEntry lastClass in
          (
              classes := !classes ^ 
                         cppfunction name v codef typEnv;
              { code = "apply(" ^ cppfunctioninst name v typEnv ^ ", " ^ codee ^ ")";
                tp = funcTyp;
                sub = compose sub sub3;
              }
          )
(*---------------------------------------------------------------------------*)  
| NoHint(Let (Binding(_, _, true), _)) | Hint(Let (Binding(_, _, true), _), _) ->
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

        let (v, e, f, vTyp) = match expr with
          | NoHint(Let (Binding(LVar(v), e, _), f)) -> (v, e, f, nextTypVar last)
          | Hint(Let (Binding(LVar(v), e, _), f), t) -> (v, e, f, t)
        in
        
        (* add the type hint for v to the type environment (or a new
           type variable in case no hint is given *)
        let typEnvNew = M.add v (Scheme([], vTyp)) typEnv in

        (* evaluate the assigned type, unify it with the potential type hint,
           then generalize the unified type; it is important to generalize
           AFTER the unification since type hints are monomorphic *)
        let { code = codee; tp = assnTyp; sub = sub1; } = eval e typEnvNew in
        let typEnvNew = applyte sub1 typEnv in
        let (vTypUni, sub2) = unification (apply sub1 vTyp) assnTyp in
        let vTypGen = generalize vTypUni typEnvNew v in
        
        (* add the unified polymorphic type for v to the map and
           apply the substitutions obtained during the previous process;
           finally determine the type of the resulting expression *)
        let typEnvNew = M.add v vTypGen typEnv in
        let sub = compose sub1 sub2 in
        let typEnvNew = applyte sub typEnvNew in
        let { code = codef; tp = retTyp; sub = sub3; } = eval f typEnvNew in

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
                      (remove (checkVar v) 
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
              sub = compose sub sub3;
            }
        )

let buildPrimitiveEnv : typeEnvironm = 
  let m = M.empty in
  let commonInttp = ArrowTyp(Concrete "Int", ArrowTyp(Concrete "Int", Concrete "Int")) in
  let commonBooltp = ArrowTyp(Concrete "Bool", ArrowTyp(Concrete "Bool", Concrete "Bool")) in
  let commonGenerictp = ArrowTyp(TypVar "a", ArrowTyp(TypVar "a", Concrete "Bool")) in
  let unaryBooltp = ArrowTyp(Concrete "Bool", Concrete "Bool") in
  let madd = M.add "operator_add" (Scheme([], commonInttp)) m in
  let msub = M.add "operator_sub" (Scheme([], commonInttp)) madd in
  let mmlt = M.add "operator_mlt" (Scheme([], commonInttp)) msub in
  let mdiv = M.add "operator_div" (Scheme([], commonInttp)) mmlt in
  let mmod = M.add "operator_mod" (Scheme([], commonInttp)) mdiv in
  let mand = M.add "operator_and" (Scheme([], commonBooltp)) mmod in
  let mor  = M.add "operator_or"  (Scheme([], commonBooltp)) mand in
  let mnot = M.add "operator_not" (Scheme([], unaryBooltp)) mor in
  let meq  = M.add "operator_eq"  (Scheme([], commonGenerictp)) mnot in
  let mif  = M.add "operator_if"  
                   (Scheme(["a"], ArrowTyp(Concrete "Bool",
                                         ArrowTyp(ArrowTyp(Concrete "Int", TypVar "a"), 
                                                  ArrowTyp(ArrowTyp(Concrete "Int", TypVar "a"), 
                                                           TypVar "a")))))
                   meq in
  let mmain = M.add "main" (Scheme([], Concrete "Int")) mif in
  mmain

let _ =
  let lexbuf = Lexing.from_channel stdin in
  let e = Parser.topLevel Scanner.tokenize lexbuf in
  let m = buildPrimitiveEnv in
  let { code = result; tp = _; sub = _; } = eval e m in

  print_endline (prelude ^
                 !classes ^
   "\nint main(){\n" ^ 
       "\tstruct primitiveEnv* env = (struct primitiveEnv*) malloc(sizeof(*env));\n\
        \tenv->operator_add = malloc(sizeof(struct operator_add_cls));\n\
        \t((struct operator_add_cls*) env->operator_add)->call = &operator_add_call;\n\
        \tenv->operator_sub = malloc(sizeof(struct operator_sub_cls));\n\
        \t((struct operator_sub_cls*) env->operator_sub)->call = &operator_sub_call;\n\
        \tenv->operator_mlt = malloc(sizeof(struct operator_mlt_cls));\n\
        \t((struct operator_mlt_cls*) env->operator_mlt)->call = &operator_mlt_call;\n\
        \tenv->operator_div = malloc(sizeof(struct operator_div_cls));\n\
        \t((struct operator_div_cls*) env->operator_div)->call = &operator_div_call;\n\
        \tenv->operator_mod = malloc(sizeof(struct operator_mod_cls));\n\
        \t((struct operator_mod_cls*) env->operator_mod)->call = &operator_mod_call;\n\
        \tenv->operator_and = malloc(sizeof(struct operator_and_cls));\n\
        \t((struct operator_and_cls*) env->operator_and)->call = &operator_and_call;\n\
        \tenv->operator_or = malloc(sizeof(struct operator_or_cls));\n\
        \t((struct operator_or_cls*) env->operator_or)->call = &operator_or_call;\n\
        \tenv->operator_not = malloc(sizeof(struct operator_not_cls));\n\
        \t((struct operator_not_cls*) env->operator_not)->call = &operator_not_call;\n\
        \tenv->operator_eq = malloc(sizeof(struct operator_eq_cls));\n\
        \t((struct operator_eq_cls*) env->operator_eq)->call = &operator_eq_call;\n\
        \tenv->operator_if = malloc(sizeof(struct operator_if_cls));\n\
        \t((struct operator_if_cls*) env->operator_if)->call = &operator_if_call;\n\
        \tprintf(\"%lld\", ((long long)" ^ result ^ "));\n\
        \treturn 0;\n\
    }")

