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
        code ^ 
        "\tprintf(\"%lld\\n\", ((long long)" ^ var ^ "));\n\
        \treturn 0;\n\
    }");
    print_string ("/*" ^ Llvm.string_of_llmodule the_module ^ "*/")
