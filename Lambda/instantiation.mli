open Ast
open Unification

val last : int ref
val lastClass : int ref
val digits : int -> int list

(* generates the next unique string given the previously generated one;
   used to generate mangled names and unique type variables during HM *)
val nextEntry : int ref -> string

(* generates the next unique type variable in lexicographical order *)
val nextTypVar : int ref -> typ

(* instantiate a type by making a new type variable for each forall *)
val instantiate : scheme -> typ

(* returns a set of type variables appearing in a type *)
val typVars : typ -> Set.Make(String).t

(* generalize a type by making a forall for each tv which is not in typEnv *)
val generalize : typ -> typeEnvironm -> string -> scheme
