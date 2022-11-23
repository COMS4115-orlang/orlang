open Unification
module L = Llvm

val the_module : L.llmodule

(* Helpers *)

(* inserts a separator between elements of a list and converts to string *)
val sep : string -> string list -> string

(* comma separated list to string *)
val commasep : string list -> string

(* remove an element from a list *)
val remove : string -> string list -> string list

(* the mangled name for the constructor *)
val mangleInit : string -> string

(* the mangled name for the call operator *)
val mangleCall : string -> string

(* the mangled name for the class *)
val mangleName : string -> string

(* the mangled name for the recursion environment *)
val mangleEnv : string -> string

(* the mangled name for the recursive function app *)
val mangleApp : string -> string

val buildPrimitiveEnv : (string * typeEnvironm)

(* generates the C code for a function;     
   acts essentially as a lambda function written in C: each function has a
   unique corresponding class with its call operator and its capture *)
val cppfunction : string -> string -> string -> typeEnvironm -> string

(* instantiate a class corresponding to a function *)
val cppfunctioninst : string -> string -> typeEnvironm -> string

val fix : string -> string -> typeEnvironm -> string -> string
