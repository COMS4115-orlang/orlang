open Ast
module M = Map.Make(String)

type substitution = typ M.t
type typeEnvironm = scheme M.t
type evalResult = 
  { code: string;
    var : string;
    tp  : typ;
    sexpr : sExpr;
    sub : substitution;
  }


(* apply a substitution to a type *)
let rec apply (sub : substitution) (tp : typ) : typ = 
  match tp with
  | Concrete _ -> tp
  | TypVar str ->
          if M.mem str sub
          then M.find str sub
          else tp
  | ArrowTyp (a, b) ->
          ArrowTyp (apply sub a, apply sub b)

(* apply a substitution to a type environment *)
let applyte (sub : substitution) (typEnv : typeEnvironm) : typeEnvironm = 
    M.map (fun (Scheme(vars, tp)) -> 
               Scheme(vars, apply sub tp)) 
          typEnv

(* compose two substitutions; sub1 gets applied before sub2 *)
let compose (sub1 : substitution) (sub2 : substitution) : substitution = 
    let sub1new = M.map (apply sub2) sub1
    in M.merge (fun _ v1 v2 -> match (v1, v2) with
                   (_, Some v) -> Some v
                 | (Some v, _) -> Some v
                 | _ -> None) 
               sub1new sub2

(* checks if a type variable occurs in a type *)
let rec occurs (str : string) (tp : typ) : bool = 
  match tp with
  | Concrete _     -> false
  | TypVar t       -> (t = str)
  | ArrowTyp(a, b) -> (occurs str a) || (occurs str b)

(* converts a type to a string for pretty print *)
let rec toString : typ -> string = function
  | Concrete s     -> s
  | TypVar s       -> s
  | ArrowTyp(a, b) -> "(" ^ (toString a) ^ ") -> (" ^ (toString b) ^ ")"

(* unify two types; return the unified type and the substitution *)
let rec unification (t1 : typ) (t2 : typ) : (typ * substitution) = 
  match (t1, t2) with
  | (Concrete s1, Concrete s2) -> 
          if s1 = s2 then (t1, M.empty)
          else raise (Failure(s1 ^ " and " ^ s2 ^ " cannot be unified"))
  | (Concrete _, TypVar s2) ->
          (t1, M.add s2 t1 M.empty)
  | (TypVar s1, Concrete _) ->
          (t2, M.add s1 t2 M.empty)
  | (TypVar s1, TypVar s2) ->
          if s1 = s2 then (t1, M.empty)
          else (t1, M.add s2 t1 M.empty)
  | (ArrowTyp(a1, b1), ArrowTyp(a2, b2)) ->
          let (_, sub1) = unification a1 a2 in
          let (_, sub2) = unification
                              (apply sub1 b1)
                              (apply sub1 b2) in
          let sub = compose sub1 sub2 in
          (apply sub t1, sub)
  | (Concrete _, ArrowTyp(_,_)) ->
          raise (Failure("cannot unify concrete type " ^ (toString t1) ^ 
                         " with arrow type " ^ (toString t2)))
  | (ArrowTyp(_,_), Concrete _) ->
          raise (Failure("cannot unify arrow type " ^ (toString t1) ^
                         " with concrete type " ^ (toString t2)))
  | (TypVar s1, ArrowTyp(_,_)) -> 
          if occurs s1 t2 
          then raise (Failure("infinite type"))
          else (t2, M.add s1 t2 M.empty)
  | (ArrowTyp(_,_), TypVar s2) ->
          if occurs s2 t1
          then raise (Failure("infinite type"))
          else (t1, M.add s2 t1 M.empty)
