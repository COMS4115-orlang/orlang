open Ast
open Unification
open Instantiation
open Semant
open Codegen
module M = Map.Make(String)
module S = Set.Make(String)

let _ =
  let lexbuf = Lexing.from_channel stdin in
  let ast = Parser.topLevel Scanner.tokenize lexbuf in
  let (prelude, env) = buildPrimitiveEnv in
  let { tp    = _; 
        sexpr = sxp; 
        sub   = _; } = Semant.check ast env in
  let { code  = code;
        var   = var } = Codegen.check sxp env in

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
        \t((struct operator_if_cls*) env->operator_if)->call = &operator_if_call;\n"
        ^ code ^ 
        "\tprintf(\"%lld\\n\", ((long long)" ^ var ^ "));\n\
        \treturn 0;\n\
    }");
    print_string ("/*" ^ Llvm.string_of_llmodule the_module ^ "*/")
