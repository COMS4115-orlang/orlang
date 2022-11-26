open Ast
module L = Llvm

type substitution = typ Map.Make(String).t
type typeEnvironm = scheme Map.Make(String).t
type evalResult = 
  { tp  : typ;
    sexpr: sExpr;
    sub : substitution;
  }
type codegenResult = 
  { code : string;
    var  : string;
    lvar : L.llvalue;
  }

(* apply a substitution to a type *)
val apply : substitution -> typ -> typ

(* apply a substitution to a type environment *)
val applyte : substitution -> typeEnvironm -> typeEnvironm 

(* compose two substitutions; sub1 gets applied before sub2 *)
val compose : substitution -> substitution -> substitution

(* checks if a type variable occurs in a type *)
val occurs : string -> typ -> bool

(* converts a type to a string for pretty print *)
val toString : typ -> string

(* unify two types; return the unified type and the substitution *)
val unification : typ -> typ -> (typ * substitution)
