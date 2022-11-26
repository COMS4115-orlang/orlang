open Ast
open Unification
open Instantiation
open Semant
open Codegen
module M = Map.Make(String)
module S = Set.Make(String)
module L = Llvm

let _ =
  let lexbuf = Lexing.from_channel stdin in
  let ast = Parser.topLevel Scanner.tokenize lexbuf in
  let (prelude, env) = buildPrimitiveEnv in
  let { tp    = _; 
        sexpr = sxp; 
        sub   = _; } = Semant.check ast env in

  let ftyp = L.function_type i32_t [||] in
  let func = L.define_function "main" ftyp the_module in
  let builder = L.builder_at_end context (L.entry_block func) in

  let { code  = code;
        var   = var ;
        lvar  = lvar; } = Codegen.check sxp env (L.const_null voidptr) builder in
  
  let tmp = "_tmp" in
  let ltmp = L.build_load lvar tmp builder in
  let parg = L.build_ptrtoint ltmp i64_t "_parg" builder in

  let formatString = L.const_stringz context "%lld\n" in
  let global = L.define_global "formatString" formatString the_module in
  let _ = L.set_unnamed_addr true global in
  let printf = L.declare_function "printf" (L.var_arg_function_type i32_t [|voidptr|])
                                 the_module in
  (* TODO: printf *)
  let castglobal = L.build_in_bounds_gep global [|L.const_int i64_t 0; L.const_int i64_t 0|] "_castglobal" builder in
  let _ = L.build_call printf [| castglobal; parg|] "_" builder in

  (* insert return 0 statement *)
  let _ = L.build_ret (L.const_int i32_t 0) builder in
  (*let _ = L.build_ret parg builder in*)

  print_endline (prelude ^
                 !classes ^
   "\nint main(){\n" ^ 
        code ^ 
        "\tprintf(\"%lld\\n\", ((long long)" ^ var ^ "));\n\
        \treturn 0;\n\
    }");
    print_string ("/*" ^ Llvm.string_of_llmodule the_module ^ "*/")
