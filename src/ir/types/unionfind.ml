(* 
 * Implementation of Union-Find, to be used for the unification algorithm
 * Heavily references the following:
    Francois Pottier's implementation (https://gitlab.inria.fr/fpottier/unionfind/-/blob/master/src/UnionFindBasic.ml)
    Elm compiler's implementation (https://github.com/elm/compiler/blob/master/compiler/src/Type/UnionFind.hs)
 *)

type 'a point =
  | Root of { mutable rank : int; mutable value : 'a }
  | Link of { mutable parent : 'a pointRef }

and 'a pointRef = 'a point ref

(* create a new Root *)
let make (v : 'a) : 'a pointRef = ref (Root { rank = 0; value = v })

(* find operation: find the representative element of the equivalence class *)
let rec find (x : 'a pointRef) : 'a pointRef =
  match !x with
  | Root _ -> x
  | Link ({ parent = y } as link) ->
      let z = find y in
      link.parent <- z;
      z

(* equiv: check if [x] and [y] are the same equivalence class *)
let equiv (x : 'a pointRef) (y : 'a pointRef) : bool =
  find x == find y

(* TODO: check if this is needed *)
(* isRepr: check if vertex is the representative element of the equivalence class *)
let isRepr (x : 'a pointRef) : bool =
  match !x with Root _ -> true | _ -> false

(* get: get value stored at representative vertex x in its equivalence class *)
let get (x : 'a pointRef) : 'a =
  let pt = find x in
  match !pt with Root { rank = _; value = v } -> v | Link _ -> assert false

(* set: update value stored at representative vertex x of [x] *)
let set (v : 'a) (x : 'a pointRef) =
  let pt = find x in
  match !pt with Root r -> r.value <- v | Link _ -> assert false

(* union operation: merge equivalence classes [x] and [y] *)
let union (x : 'a pointRef) (y : 'a pointRef) : 'a pointRef =
  let rx, ry = (find x, find y) in
  if rx == ry then rx
  else
    match (!rx, !ry) with
    | Root ({ rank = rankx; _ } as nx), Root { rank = ranky; _ } ->
        if rankx > ranky then (
          ry := Link { parent = rx };
          rx)
        else if rankx < ranky then (
          rx := Link { parent = ry };
          ry)
        else (
          ry := Link { parent = rx };
          nx.rank <- rankx + 1;
          rx)
    | _, _ -> assert false

(* unionWith: union but invokes a user-specific function to compute
              a new value v for the equivalence class *)
let unionWith (f : 'a -> 'a -> 'a) (x : 'a pointRef) (y : 'a pointRef) :
    'a pointRef =
  let rx, ry = (find x, find y) in
  if rx == ry then rx
  else
    match (!rx, !ry) with
    | ( Root ({ rank = rankx; value = valx } as nx),
        Root ({ rank = ranky; value = valy } as ny) ) ->
        let newv = f valx valy in
        if rankx > ranky then (
          ry := Link { parent = rx };
          nx.value <- newv;
          rx)
        else if rankx < ranky then (
          rx := Link { parent = ry };
          ny.value <- newv;
          ry)
        else (
          ry := Link { parent = rx };
          nx.rank <- rankx + 1;
          rx)
    | _, _ -> assert false
