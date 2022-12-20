open Ast
open Unification
open Instantiation
open Semant
open Codegen

module M = Map.Make(String)
module S = Set.Make(String)
module L = Llvm

let read_file filename =
    let channel = open_in filename in
    let str = really_input_string channel (in_channel_length channel) in
    close_in channel;
    str

let _ =
  let (input, output) = 
      match Sys.argv with
        [|_; input; output|] -> (input, output)
      | _                 -> raise (Failure ("usage: orlang.native <input-file> <output-file>"))
  in 
  let contents = (read_file "tests/prelude.orl") ^ (read_file input) in
  let lexbuf = Lexing.from_string contents in
  let ast = Parser.topLevel Scanner.tokenize lexbuf in
  let env = M.empty in
  let { tp    = _; 
        sexpr = sxp; 
        sub   = _; } = Semant.check ast env in
  
  (* define main function *)
  let ftyp = L.function_type i32_t [||] in
  let func = L.define_function "main" ftyp the_module in
  let builder = L.builder_at_end context (L.entry_block func) in

  (* insert the body of the main function *)
  let _ = Codegen.check sxp env (L.const_null voidptr) builder in

  (* return 0 *)
  let _ = L.build_ret (L.const_int i32_t 0) builder in

  let channel = open_out output in
  output_string channel (Llvm.string_of_llmodule the_module);
  close_out channel
