open Unification
module L = Llvm

val the_module : L.llmodule

(* All but the last element of a list *)
val init : 'a list -> 'a list

(* last element of a list *)
val lst : 'a list -> 'a

(* Helpers *)
val checkVar : string -> string

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

(* general C skeleton for a unary function *)
val primitiveUnaryFunc : string -> string -> string

(* general C skeleton for a binary function *)
val primitiveBinaryFunc : string -> string -> string

(* C code for the if statement *)
val ifstatement : string

(* function that performs function application *)
val applyFunc : string

(* struct corresponding to the initial state of the env *)
val primitiveEnv : string

(* fixed includes and classes *)
val prelude : string

(* generates the C code for a function;     
   acts essentially as a lambda function written in C: each function has a
   unique corresponding class with its call operator and its capture *)
val cppfunction : string -> string -> string -> typeEnvironm -> string

(* instantiate a class corresponding to a function *)
val cppfunctioninst : string -> string -> typeEnvironm -> string

val fix : string -> string -> typeEnvironm -> string -> string
