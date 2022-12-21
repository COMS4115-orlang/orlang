open Ast
open Unification
module M = Map.Make(String)
module S = Set.Make(String)

let last = ref 0
let lastClass = ref 0
let lastTemp = ref 0
let rec digits (x : int) : int list = 
  if x < 10 then [x]
  else (x mod 10) :: (digits (x / 10))

(* generates the next unique string given the previously generated one;
   used to generate mangled names and unique type variables during HM *)
let nextEntry (x : int ref) : string = 
(
    x := !x + 1;
    let l = List.map Char.chr (List.map ((+) (Char.code 'a')) (digits !x)) in
    String.of_seq (List.to_seq l)
)

(* generates the next unique type variable in lexicographical order *)
let nextTypVar (x : int ref) : typ =
    TypVar (nextEntry x)

(* instantiate a type by making a new type variable for each forall *)
let instantiate (sch : scheme) : typ =
    let Scheme(vars, tp) = sch in
    let sub = List.fold_left (fun m var -> M.add var (nextTypVar last) m) 
                             M.empty 
                             vars
    in apply sub tp

(* returns a set of type variables appearing in a type *)
let rec typVars : typ -> S.t = function
    Concrete _     -> S.empty
  | Unit           -> S.empty
  | TypVar s       -> S.singleton s
  | ArrowTyp(a, b) -> S.union (typVars a) (typVars b)
  | ListTyp t      -> typVars t

(* generalize a type by making a forall for each tv which is not in typEnv *)
let generalize (tp : typ) (typEnv : typeEnvironm) (var : string) : scheme = 
    let typvars = List.of_seq (S.to_seq (typVars tp)) in
    let forall  = List.filter 
                   (fun s -> not (M. exists 
                             (fun mVar (Scheme(_, t)) -> mVar <> var && occurs s t) typEnv))
                   typvars in
    Scheme(forall, tp)
