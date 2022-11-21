open Ast
open Unification
open Instantiation
open Cpp
open Semant
module M = Map.Make(String)
module S = Set.Make(String)

let classes = ref ""

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
  let ast = Parser.topLevel Scanner.tokenize lexbuf in
  let env = buildPrimitiveEnv in
  let sast = Semant.check ast env in
  let { code = result; tp = _; sexpr = sxp; sub = _; } = sast in

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

