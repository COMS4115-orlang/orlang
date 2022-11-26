open Ast
open Unification
open Instantiation
open Semant
open Codegen
module M = Map.Make(String)
module S = Set.Make(String)
module L = Llvm

let _ =
  let mode = (match Sys.argv with
              | [| _ |]           -> "-llvm"
              | [| _ ; "-c" |]    -> "-c"
              | [| _ ; "-llvm" |] -> "-llvm"
              | _                 -> 
                      raise (Failure("usage: " ^ Sys.argv.(0) ^ " <mode=-c/-llvm>\n"));
             ) in
  
  let lexbuf = Lexing.from_channel stdin in
  let ast = Parser.topLevel Scanner.tokenize lexbuf in
  let (prelude, env) = buildPrimitiveEnv in
  let { tp    = _; 
        sexpr = sxp; 
        sub   = _; } = Semant.check ast env in

  (* define main function *)
  let ftyp = L.function_type i32_t [||] in
  let func = L.define_function "main" ftyp the_module in
  let builder = L.builder_at_end context (L.entry_block func) in

  (* insert the body of the main function *)
  let { code  = code;
        var   = var ;
        lvar  = lvar; } = Codegen.check sxp env (L.const_null voidptr) builder in
  
  (* get result for printing *)
  let tmp = "_tmp" in
  let ltmp = L.build_load lvar tmp builder in
  let parg = L.build_ptrtoint ltmp i64_t "_parg" builder in

  (* declare printf prototype *)
  let formatString = L.const_stringz context "%lld\n" in
  let global = L.define_global "formatString" formatString the_module in
  let _ = L.set_unnamed_addr true global in
  let printf = L.declare_function "printf" (L.var_arg_function_type i32_t [|voidptr|])
                                 the_module in

  (* call printf *)
  let castglobal = L.build_in_bounds_gep global 
                   [|L.const_int i64_t 0; L.const_int i64_t 0|] 
                   "_castglobal" builder in
  let _ = L.build_call printf [| castglobal; parg|] "_" builder in

  (* return 0 *)
  let _ = L.build_ret (L.const_int i32_t 0) builder in

  if mode = "-c"
  then print_endline (prelude ^
                      !classes ^
                      "\nint main(){\n" ^ 
                      code ^ 
                      "\tprintf(\"%lld\\n\", ((long long)" ^ var ^ "));\n\
                       \treturn 0;\n\
                       }")
  else print_string (Llvm.string_of_llmodule the_module)
