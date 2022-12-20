open Ast
open Unification
open Instantiation
module M = Map.Make(String)
module S = Set.Make(String)
module L = Llvm

let classes = ref ""

let context    = L.global_context()
let the_module = L.create_module context "Orlang"
let i8_t       = L.i8_type context
let i32_t      = L.i32_type context
let i64_t      = L.i64_type context
let float_t    = L.double_type context
let voidptr    = L.pointer_type i8_t
let voidptrptr = L.pointer_type voidptr

let ftypUnr    = L.function_type voidptr (Array.of_list [voidptr; voidptr])
let ftypBin    = L.function_type voidptr (Array.of_list [voidptr; voidptr])
let funcptr    = L.pointer_type ftypBin
let funcptrptr = L.pointer_type funcptr

(* Helpers *)

(* inserts a separator between elements of a list and converts to string *)
let rec sep (sym : string) : string list -> string = function
  | x :: [] -> x
  | x :: xs -> x ^ sym ^ (sep sym xs)
  | _ -> ""

(* inserts a prefix in front of each element of a list and concatenates *)
let rec pref (sym : string) : string list -> string = function
  | x :: [] -> sym ^ x
  | x :: xs -> sym ^ x ^ (pref sym xs)
  | _ -> ""

(* zips a list with their indices *)
let zipWithIndex (xs : 'a list) :
                 ('a * int) list = 
    let currIndex = ref 0 in
    List.map (fun v ->
                  currIndex := !currIndex + 1;
                  (v, !currIndex)
             ) xs

(* remove an element from an indexed list *)
let rec removeIndexed (xs : ('a * int) list)
                  (v : 'a)
                  : ('a * int) list =
  match xs with
  | [] -> []
  | (x, i) :: ys -> if x = v 
                    then ys
                    else (x, i) :: (removeIndexed ys v)

(* normal zip function *)
let rec zip (xs : 'a list) 
            (ys : 'b list) = 
  match (xs, ys) with
  | (_, []) -> []
  | ([], _) -> []
  | (x :: xss, y :: yss) -> (x, y) :: zip xss yss


(* comma separated list to string *)
let commasep (x : string list) : string = sep ", " x

(* remove an element from a list *)
let rec remove (str : string) : string list -> string list = function
  | [] -> []
  | x :: xs -> if x = str then remove str xs
               else x :: (remove str xs)

(* the mangled name for the constructor *)
let mangleInit (funName : string) : string = 
    funName ^ "_init"

(* the mangled name for the call operator *)
let mangleCall (funName : string) : string =
    funName ^ "_call"

(* the mangled name for the class *)
let mangleName (funName : string) : string = 
    funName ^ "_cls"

(* the mangled name for the recursion environment *)
let mangleEnv (funName : string) : string =
    funName ^ "_env"

(* the mangled name for the recursive function app *)
let mangleApp (funName : string) : string =
    funName ^ "_app"

(* builds function definition & space alloc for parameters *)
let llvmFuncDef (name : string)      (* the name of the function *)
                (args : string list) (* the names of the parameters *)
                : (L.llvalue *       (* llvalue of function *)
                   L.llbuilder *     (* function's builder *)
                   L.llvalue list) = (* llvalues of parameters *)
    (* get llvm function type void* (void* , ...) *)
    let ftyp = L.function_type voidptr (Array.of_list (List.map (fun _ -> voidptr) args)) in
    (* create function with the above name and type *)
    let func = L.define_function name ftyp the_module in
    (* begin writing the function *)
    let builder = L.builder_at_end context (L.entry_block func) in

    let add_formal (n, p) =
        (* bind the parameter to a name *)
        L.set_value_name n p;
        (* allocate space for the parameter on the stack *)
        let local = L.build_alloca voidptr n builder in
        (* store parameter value on the stack *)
        ignore (L.build_store p local builder);
        local
    in 
    let paramList = 
        List.map add_formal (List.combine args
                                (Array.to_list (L.params func))) in
    (func, builder, paramList)

(* Llvm code for assigning a value to a member of a struct *)
let llvmAssignMember (allocd_struct : L.llvalue) (* llvalue of structure *)
                     (p : L.llvalue)             (* llvalue of stored value *)
                     (currIndex : int)           (* index in structure *)
                     (builder : L.llbuilder)     (* builder where to put this *)
                     : unit =
    (* load the argument value *)
    let argval = L.build_load p "argval" builder in
    (* load the structure *)
    let struct_load = L.build_load allocd_struct "struct_load" builder in
    (* cast structure to void** *)
    let struct_cast = L.build_bitcast struct_load 
                      voidptrptr "struct_cast" builder in
    (* get reference to argument position in the structure *)
    let elem_ptr    = L.build_in_bounds_gep struct_cast 
                                            [| L.const_int i64_t currIndex |]
                                            "elem_ptr" builder in
    (* store the value *)
    ignore(L.build_store argval elem_ptr builder)

(* function that performs function application *)
let applyFunc : L.llvalue =    (* llvalue of the apply function *)
    (* function signature and param space *)
    let (func, builder, f, arg) = 
        (match llvmFuncDef "_apply" ["f"; "arg"] with
         | (func, builder, [f; arg]) -> (func, builder, f, arg)
         | _ -> assert false)
    in

    (* load ptrptr f *)
    let f_load = L.build_load f "f_load" builder in 
    (* cast it to function ptr *)
    let f_cast = L.build_bitcast f_load funcptrptr "f_cast" builder in
    let f_fptr = L.build_load f_cast "f_fptr" builder in
    (* load the arguments to be passed *)
    let arg1   = L.build_load f "arg1" builder in
    let arg2   = L.build_load arg "arg2" builder in
    (* call function *)
    let retval = L.build_call f_fptr (Array.of_list [arg1; arg2]) "retval" builder in
    let _ = L.build_ret retval builder in

    func

(* generate a call to the `apply` function with arguments f and arg *)
let callApply (var : string)          (* name of result *)
              (fvar : string)         (* name of function *)
              (flvar : L.llvalue)     (* llvalue of function *)
              (argvar : string)       (* name of argument *)
              (arglvar : L.llvalue)   (* llvalue of argument *)
              (builder : L.llbuilder) (* builder where to insert this *)
              : L.llvalue =           (* llvalue of result *)
    (* get llvalue of apply function and alloc space for result *)
    let apply = applyFunc in
    let local = L.build_alloca voidptr var builder in
    
    (* call apply function and store result in llvalue *)
    let fload = L.build_load flvar "_fload" builder in
    let argload = L.build_load arglvar "_argload" builder in
    let call = L.build_call apply [|fload; argload|] "call" builder in
    let _ = L.build_store call local builder in

    local

(* function that performs function application *)
let ifFunc : L.llvalue =    (* llvalue of the if function *)
    (* function signature and param space *)
    let (func, builder, c, t, e) = 
        (match llvmFuncDef "_if_func" ["c"; "t"; "e"] with
         | (func, builder, [c; t; e]) -> (func, builder, c, t, e)
         | _ -> assert false)
    in

    let nullvar = L.build_alloca voidptr "_nullvar" builder in
    let _ = L.build_store (L.const_null voidptr) nullvar builder in

    (* then block *)
    let then_bb = L.append_block context "then" func in
    let then_b = L.builder_at_end context then_bb in
    let res = callApply "_res"
                        "t" t 
                        "NULL" nullvar
                        then_b in
    let loadres = L.build_load res "_loadres" then_b in
    let _ = L.build_ret loadres then_b in

    (* else block *)
    let else_bb = L.append_block context "else" func in
    let else_b = L.builder_at_end context else_bb in
    let res = callApply "_res"
                        "e" e
                        "NULL" nullvar
                        else_b in
    let loadres = L.build_load res "_loadres" else_b in
    let _ = L.build_ret loadres else_b in
    
    (* branch *)
    let loadc = L.build_load c "_loadc" builder in
    let boolc = L.build_icmp L.Icmp.Eq loadc (L.const_null voidptr) "_res" builder in
    let _ = L.build_cond_br boolc else_bb then_bb builder in

    func

let lenFunc : L.llvalue = 
    let (func, builder, c) = 
        (match llvmFuncDef "_len_func" ["c"] with
         | (func, builder, [c]) -> (func, builder, c)
         | _ -> assert false)
    in
    (* blocks *)
    let cond_bb = L.append_block context "_len_cond" func in
    let cond_b = L.builder_at_end context cond_bb in
    let merge_bb = L.append_block context "_len_merge" func in
    let merge_b = L.builder_at_end context merge_bb in
    let next_bb = L.append_block context "_len_next" func in
    let next_b = L.builder_at_end context next_bb in

    (* initialize len to 0 and cptr *)
    let len = L.build_alloca voidptr "_len_val" builder in
    let const = L.build_inttoptr (L.const_int i64_t 0) voidptr "const" builder in
    let _ = L.build_store const len builder in

    let loadc = L.build_load c "_loadc" builder in
    let cptr = L.build_alloca voidptr "_cptrs" builder in
    let _ = L.build_store loadc cptr builder in

    let loadc = L.build_load cptr "_loadc" cond_b in
    let intc = L.build_ptrtoint loadc i64_t "_bit" cond_b in
    let boolc = L.build_icmp L.Icmp.Eq intc (L.const_int i64_t 0) "_res" cond_b in

    (* increment len *)
    let loadres = L.build_load len "_loadres" next_b in
    let lenres = L.build_ptrtoint loadres i64_t "_loadres" next_b in
    let ptrplusone = L.build_add lenres (L.const_int i64_t 1) "_ptrplusone" next_b in
    let ptrptrplusone = L.build_inttoptr ptrplusone voidptr "_ptrptrplusone" next_b in
    let _ = L.build_store ptrptrplusone len next_b in

    (* goto next ptr *)
    let loadc = L.build_load cptr "_loadcmm" next_b in
    let c' = L.build_pointercast loadc voidptrptr "_cptr" next_b in 
    (* cast to void** for some reason *)
    let sptr'   = L.build_gep c' [|(L.const_int i64_t 1)|] "" next_b in
    let sptrval = L.build_load sptr' "_sptrvalx" next_b in (* get pointer to val *)
    let _ = L.build_store sptrval cptr next_b in
    let _ = L.build_br cond_bb next_b in

    (* add terminals *)

    (* terminate *)
    let loadres = L.build_load len "_loadres" merge_b in
    let _ = L.build_ret loadres merge_b in

    (* branch condition *)
    let _ = L.build_cond_br boolc merge_bb next_bb cond_b in

    let _ = L.build_br cond_bb builder in
    func

let printFunc : L.llvalue = 
    let (func, builder, c) = 
        (match llvmFuncDef "_print_func" ["c"] with
         | (func, builder, [c]) -> (func, builder, c)
         | _ -> assert false)
    in
    (* blocks *)
    let cond_bb = L.append_block context "_len_cond" func in
    let cond_b = L.builder_at_end context cond_bb in
    let merge_bb = L.append_block context "_len_merge" func in
    let merge_b = L.builder_at_end context merge_bb in
    let next_bb = L.append_block context "_len_next" func in
    let next_b = L.builder_at_end context next_bb in

    (* initialize len to 0 and cptr *)
    let loadc = L.build_load c "_loadc" builder in
    let cptr = L.build_alloca voidptr "_cptrs" builder in
    let _ = L.build_store loadc cptr builder in

    let loadc = L.build_load cptr "_loadc" cond_b in
    let intc = L.build_ptrtoint loadc i64_t "_bit" cond_b in
    let boolc = L.build_icmp L.Icmp.Eq intc (L.const_int i64_t 0) "_res" cond_b in

    (* goto next ptr *)
    let loadc = L.build_load cptr "_loadcmm" next_b in
    let c' = L.build_pointercast loadc voidptrptr "_cptr" next_b in 
    (* cast to void** for some reason *)

(*---*)
  let sptrval' = L.build_load c' "_sptrval" next_b in 
  let vptr1 = L.build_pointercast sptrval' voidptrptr "_vptr" next_b in 
  let value = L.build_load vptr1 "_value" next_b in 
  let parg = L.build_ptrtoint value i64_t "_parg" next_b in
  let charify = L.build_trunc parg i32_t "_chard" next_b in

  (* declare printf prototype *)
  let formatString = L.const_stringz context "%c" in
  let global = L.define_global "formatString" formatString the_module in
  let _ = L.set_unnamed_addr true global in
  let printf = L.declare_function "printf" (L.var_arg_function_type i32_t [|voidptr|])
                                 the_module in

  (* call printf *)
  let castglobal = L.build_in_bounds_gep global 
                   [|L.const_int i64_t 0; L.const_int i64_t 0|] 
                   "_castglobal" next_b in
  let _ = L.build_call printf [| castglobal; charify|] "_" next_b in
(*---*)

    let sptr'   = L.build_gep c' [|(L.const_int i64_t 1)|] "" next_b in
    let sptrval = L.build_load sptr' "_sptrvalx" next_b in (* get pointer to val *)
    let _ = L.build_store sptrval cptr next_b in
    let _ = L.build_br cond_bb next_b in

    (* add terminals *)

    (* terminate *)
    let const = L.build_inttoptr (L.const_int i64_t 0) 
                                  voidptr
                                  "const" builder in
    let _ = L.build_ret const merge_b in

    (* branch condition *)
    let _ = L.build_cond_br boolc merge_bb next_bb cond_b in
    let _ = L.build_br cond_bb builder in

    func

(* find the index of an element in a list *)
let find x ys = 
    let rec helper x index = function
    | []     -> raise(Failure("impossible"))
    | y :: ys -> if x = y then index
                          else helper x (index + 1) ys
    in helper x 0 ys

(* load all the variables in the env except for one *)
let loadCEnvExcept (typEnv : typeEnvironm)  (* the type environment *)
                   (llvmEnv : L.llvalue)    (* its associated llvalue *)
                   (excepts : string list)  (* variables to exclude *)
                   (builder : L.llbuilder)  (* builder for instructions *)
                   : L.llvalue list =       (* list of loaded vars *)
    let capture = (M.fold (fun k _ acc -> k :: acc) typEnv []) in
    let captureIndex = zipWithIndex capture in
    let captureFiltr = List.fold_left (fun a c -> removeIndexed a c) captureIndex excepts in
    List.fold_left
         (fun acc (v, currIndex) ->
              let var = "_" ^ (nextEntry lastTemp) in
              (* load structure, cast it, index into it *)
              let struct_load = L.build_load llvmEnv "struct_load" builder in
              let struct_cast = L.build_bitcast struct_load 
                                  voidptrptr "struct_cast" builder in
              let elem_ptr    = L.build_in_bounds_gep struct_cast
                                  [| L.const_int i64_t (currIndex) |]
                                  "elem_ptr" builder in
              (* load the result to be passed to the init call *)
              let load = L.build_load elem_ptr (var ^ "_load") builder in

              acc @ [load]
         )
         []
         captureFiltr

(* load all the variables in the env except for one *)
let loadEnvExcept (typEnv : typeEnvironm)  (* the type environment *)
                  (llvmEnv : L.llvalue)    (* its associated llvalue *)
                  (except : string)        (* variable to exclude *)
                  (builder : L.llbuilder)  (* builder for instructions *)
                  : L.llvalue list =       (* list of loaded vars *)
    let capture = (M.fold (fun k _ acc -> k :: acc) typEnv []) in
    let captureIndex = zipWithIndex capture in
    let captureFiltr = removeIndexed captureIndex except in
    List.fold_left
         (fun acc (v, currIndex) ->
              let var = "_" ^ (nextEntry lastTemp) in
              (* load structure, cast it, index into it *)
              let struct_load = L.build_load llvmEnv "struct_load" builder in
              let struct_cast = L.build_bitcast struct_load 
                                  voidptrptr "struct_cast" builder in
              let elem_ptr    = L.build_in_bounds_gep struct_cast
                                  [| L.const_int i64_t (currIndex) |]
                                  "elem_ptr" builder in
              (* load the result to be passed to the init call *)
              let load = L.build_load elem_ptr (var ^ "_load") builder in

              acc @ [load]
         )
         []
         captureFiltr

(* instantiate a class corresponding to a function *)
let cppfunctioninst (var : string)           (* the varname of the result *)
                    (name : string)          (* the name of the function  *)
                    (llvm_init : L.llvalue)  (* the llvalue of its init function *)
                    (arg : string)           (* the name of the argument *)
                    (typEnv : typeEnvironm)  (* the type environment *)
                    (llvmEnv : L.llvalue)    (* llvalue of the "env" *)
                    (builder : L.llbuilder)  (* builder where to insert this *)
                    : L.llvalue =            (* llvalue of the result *)

    let llvmArgs = loadEnvExcept typEnv llvmEnv arg builder in
 
    (* call the llvm_init function with the llvmargs *)
    let local = L.build_alloca voidptr var builder in
    let call = L.build_call llvm_init (Array.of_list llvmArgs) "call" builder in
    let _ = L.build_store call local builder in
    
    local

(* instantiate a class corresponding to a function *)
let cppCfunctioninst (var : string)           (* the varname of the result *)
                    (name : string)          (* the name of the function  *)
                    (llvm_init : L.llvalue)  (* the llvalue of its init function *)
                    (args : string list)           (* the name of the argument *)
                    (typEnv : typeEnvironm)  (* the type environment *)
                    (llvmEnv : L.llvalue)    (* llvalue of the "env" *)
                    (builder : L.llbuilder)  (* builder where to insert this *)
                    : L.llvalue              (* llvalue of the result *)
                    = 
    let llvmArgs = loadCEnvExcept typEnv llvmEnv args builder in
 
    (* call the llvm_init function with the llvmargs *)
    let local = L.build_alloca voidptr var builder in
    let call = L.build_call llvm_init (Array.of_list llvmArgs) "call" builder in
    let _ = L.build_store call local builder in
    local

(* generates the C code for a function;     
   acts essentially as a lambda function written in C: each function has a
   unique corresponding class with its call operator and its capture *)
let rec cppfunction (name : string)           (* name of the function *)
                    (arg : string)            (* argument name *)
                    (body : (sExpr *          (* sExpr of function body *)
                             typeEnvironm))   (* env to evaluate the body in *)
                    (typEnv : typeEnvironm)   (* the type environment *)
                    : L.llvalue =             (* llvalue of the init function *)
    let dummyScheme = Scheme([], (Concrete "Int")) in
    let capture = (M.fold (fun k _ acc -> k :: acc) 
                   (M.add arg dummyScheme typEnv) 
                   []) in

(*---------------------------------------------------------------------------*)  
    (* define the structure associated with this function *)
    let structT = L.named_struct_type context ("struct." ^ mangleName name) in
    let strptrT = L.pointer_type structT in
    let _ = L.struct_set_body structT
                         (Array.append 
                             (Array.of_list [funcptr]) 
                             (Array.make (List.length capture) voidptr))
                         false in

(*---------------------------------------------------------------------------*)  
    (* define the call function and allocate space for params *)
    let (fn_call, builder, params) = llvmFuncDef (mangleCall name) ["genenv"; "arg"] in
    
    let (llvm_genenv, llvm_arg) = 
        (match params with
         | [llvm_genenv; llvm_arg] -> (llvm_genenv, llvm_arg)
         | _ -> assert false)
    in

    (* cast struct *)
    let allocd_struct = L.build_alloca strptrT "env" builder in
    let struct_load = L.build_load llvm_genenv "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load strptrT "struct_cast" builder in
    let _ = L.build_store struct_cast allocd_struct builder in

    (* store argument in "capture" *)
    let argIndex = 1 + find arg capture in
    let _ = llvmAssignMember allocd_struct llvm_arg argIndex builder in

    (* insert the body of the call function *)
    let (e, te) = body in
    let { var   = evar;
          lvar  = elvar; } = check e te allocd_struct builder in

    (* load result and return it *)
    let ret = L.build_load elvar "_ret" builder in
    let _ = L.build_ret ret builder in

(*---------------------------------------------------------------------------*)  
    (* define the init function and allocate space for params *)
    let (fn_init, builder, params) = llvmFuncDef (mangleInit name) (remove arg capture) in
    
    (* malloc structure and cast it *)
    let allocd_struct = L.build_alloca strptrT "reserved" builder in
    let space = L.build_malloc structT "space" builder in
    let _ = L.build_store space allocd_struct builder in

    (* store pointer to call in struct *)
    let struct_load = L.build_load allocd_struct "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load funcptrptr "struct_cast" builder in
    let _ = L.build_store fn_call struct_cast builder in

    (* store function arguments into structure *)
    let captureIndex = zipWithIndex capture in
    let captureFiltr = removeIndexed captureIndex arg in
    let captureParam = zip captureFiltr params in
    let _ = (List.iter 
                (fun ((_, currIndex), p) ->
                    (* assign the argument to the member of the struct *)
                    ignore(llvmAssignMember allocd_struct p currIndex builder)
                ) captureParam) in

    (* load structure, cast it to void*, return it *)
    let struct_load = L.build_load allocd_struct "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load voidptr "struct_cast" builder in
    ignore(L.build_ret struct_cast builder);

    fn_init

(* generates the C code for a function;     
   acts essentially as a lambda function written in C: each function has a
   unique corresponding class with its call operator and its capture *)
and cppCfunction (name : string)           (* name of the function *)
                    (args : string list)            (* argument name *)
                    (body : (sExpr *          (* sExpr of function body *)
                             typeEnvironm))   (* env to evaluate the body in *)
                    (typEnv : typeEnvironm)   (* the type environment *)
                    : L.llvalue               (* llvalue of the init function *)
                    = 
    let dummyScheme = Scheme([], (Concrete "Int")) in
    let rec addAllArgs m al =
        match al with
        | x::xs -> addAllArgs (M.add x dummyScheme m) xs
        | _    -> m
    in  
    let capture = (M.fold (fun k _ acc -> k :: acc) (addAllArgs typEnv args) []) in

    (* define the structure associated with this function *)
    let structT = L.named_struct_type context ("struct." ^ mangleName name) in
    let strptrT = L.pointer_type structT in
    let _ = L.struct_set_body structT
                         (Array.append 
                             (Array.of_list [funcptr]) 
                             (Array.make (List.length capture) voidptr))
                         false in

    (* define the call function and allocate space for params *)
    let (fn_call, builder, params) = llvmFuncDef (mangleCall name) ["genenv"; "arg"] in

    let (llvm_genenv, llvm_arg) = 
        (match params with
         | [llvm_genenv; llvm_arg] -> (llvm_genenv, llvm_arg)
         | _ -> assert false)
    in
    
    let num_args = List.length args in
    let larg' = L.build_load llvm_arg "_sptrval" builder in (* get pointer to val *)
    let larg  = L.build_pointercast larg' voidptrptr "_larg" builder in 
    (* cast to void** for some reason *)
    let rec unpack llargs n acc =
        (if (n > 1)
         then 
           let sptrval' = L.build_load llargs "_sptrval" builder in 
           (* get pointer to val *)
           let vptr1 = L.build_pointercast sptrval' voidptrptr "_vptr" builder in 
           (* cast to void** for some reason *)
           let sptr'   = L.build_gep llargs [|(L.const_int i64_t 1)|] "" builder in
           let sptrval = L.build_load sptr' "_sptrval" builder in 
           (* get pointer to val *)
           let vptr' = L.build_pointercast sptrval voidptrptr "_vptr" builder in 
           (* cast to void** for some reason *)
           unpack vptr' (n - 1) (vptr1 :: acc)
         else
           let local = L.build_alloca voidptr "" builder in
           let sptr' = L.build_pointercast llargs voidptr "" builder in
           let _ = L.build_store sptr' local builder in
           List.rev (local :: acc)) in
    let unpacked_llvm_args = unpack larg num_args [] in

    (* cast struct *)
    let allocd_struct = L.build_alloca strptrT "env" builder in
    let struct_load = L.build_load llvm_genenv "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load strptrT "struct_cast" builder in
    let _ = L.build_store struct_cast allocd_struct builder in

    (* store argument in "capture" *)
    let assignments = zip args unpacked_llvm_args in 
    let _ = List.map (fun (a, lv) -> let argIndex = 1 + find a capture in
                      llvmAssignMember allocd_struct lv argIndex builder) assignments in
    
    (* insert the body of the call function *)
    let (e, te) = body in
    let { var   = evar;
          lvar  = elvar; } = check e te allocd_struct builder in

    (* load result and return it *)
    let ret = L.build_load elvar "_ret" builder in
    let _ = L.build_ret ret builder in

    (* define the init function and allocate space for params *)
    let capture_without_args = List.fold_left (fun a b -> remove b a) capture args in
    let (fn_init, builder, params) = llvmFuncDef (mangleInit name) capture_without_args in
    
    (* malloc structure and cast it *)
    let allocd_struct = L.build_alloca strptrT "reserved" builder in
    let space = L.build_malloc structT "space" builder in
    let _ = L.build_store space allocd_struct builder in

    (* store pointer to call in struct *)
    let struct_load = L.build_load allocd_struct "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load funcptrptr "struct_cast" builder in
    let _ = L.build_store fn_call struct_cast builder in

    (* store function arguments into structure *)
    let captureIndex = zipWithIndex capture in
    let captureFiltr = List.fold_left (fun a c -> removeIndexed a c) captureIndex args in
    let captureParam = zip captureFiltr params in
    let _ = (List.iter 
                (fun ((_, currIndex), p) ->
                    (* assign the argument to the member of the struct *)
                    ignore(llvmAssignMember allocd_struct p currIndex builder)
                ) captureParam) in

    (* load structure, cast it to void*, return it *)
    let struct_load = L.build_load allocd_struct "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load voidptr "struct_cast" builder in
    ignore(L.build_ret struct_cast builder);
    fn_init

(* generates the C code for a function;     
   acts essentially as a lambda function written in C: each function has a
   unique corresponding class with its call operator and its capture *)
and cppMfunction (name : string)           (* name of the function *)
                    (args : string list)            (* argument name *)
                    (body : (sExpr *          (* sExpr of function body *)
                             typeEnvironm))   (* env to evaluate the body in *)
                    (typEnv : typeEnvironm)   (* the type environment *)
                    : L.llvalue               (* llvalue of the init function *)
                    = 
    let dummyScheme = Scheme([], (Concrete "Int")) in
    let rec addAllArgs m al =
        match al with
        | x::xs -> addAllArgs (M.add x dummyScheme m) xs
        | _    -> m
    in  
    let capture = (M.fold (fun k _ acc -> k :: acc) (addAllArgs typEnv args) []) in

    (* define the structure associated with this function *)
    let structT = L.named_struct_type context ("struct." ^ mangleName name) in
    let strptrT = L.pointer_type structT in
    let _ = L.struct_set_body structT
                         (Array.append 
                             (Array.of_list [funcptr]) 
                             (Array.make (List.length capture) voidptr))
                         false in

    (* define the call function and allocate space for params *)
    let (fn_call, builder, params) = llvmFuncDef (mangleCall name) ["genenv"; "arg"] in

    let (llvm_genenv, llvm_arg) = 
        (match params with
         | [llvm_genenv; llvm_arg] -> (llvm_genenv, llvm_arg)
         | _ -> assert false)
    in
    
    let num_args = List.length args in
    let larg' = L.build_load llvm_arg "_sptrval" builder in (* get pointer to val *)
    let larg  = L.build_pointercast larg' voidptrptr "_larg" builder in 
    (* cast to void** for some reason *)
    let rec unpack llargs n acc =
        (if (n > 0)
         then 
           let sptrval' = L.build_load llargs "_sptrval" builder in 
           (* get pointer to val *)
           let vptr1 = L.build_pointercast sptrval' voidptrptr "_vptr" builder in 
           (* cast to void** for some reason *)
           let sptr'   = L.build_gep llargs [|(L.const_int i64_t 1)|] "" builder in
           let sptrval = L.build_load sptr' "_sptrval" builder in 
           (* get pointer to val *)
           let vptr' = L.build_pointercast sptrval voidptrptr "_vptr" builder in 
           (* cast to void** for some reason *)
           unpack vptr' (n - 1) (vptr1 :: acc)
         else
           List.rev acc) in
    let unpacked_llvm_args = unpack larg num_args [] in

    (* cast struct *)
    let allocd_struct = L.build_alloca strptrT "env" builder in
    let struct_load = L.build_load llvm_genenv "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load strptrT "struct_cast" builder in
    let _ = L.build_store struct_cast allocd_struct builder in

    (* store argument in "capture" *)
    let assignments = zip args unpacked_llvm_args in 
    let _ = List.map (fun (a, lv) -> let argIndex = 1 + find a capture in
                      llvmAssignMember allocd_struct lv argIndex builder) assignments in
    
    (* insert the body of the call function *)
    let (e, te) = body in
    let { var   = evar;
          lvar  = elvar; } = check e te allocd_struct builder in

    (* load result and return it *)
    let ret = L.build_load elvar "_ret" builder in
    let _ = L.build_ret ret builder in

    (* define the init function and allocate space for params *)
    let capture_without_args = List.fold_left (fun a b -> remove b a) capture args in
    let (fn_init, builder, params) = llvmFuncDef (mangleInit name) capture_without_args in
    
    (* malloc structure and cast it *)
    let allocd_struct = L.build_alloca strptrT "reserved" builder in
    let space = L.build_malloc structT "space" builder in
    let _ = L.build_store space allocd_struct builder in

    (* store pointer to call in struct *)
    let struct_load = L.build_load allocd_struct "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load funcptrptr "struct_cast" builder in
    let _ = L.build_store fn_call struct_cast builder in

    (* store function arguments into structure *)
    let captureIndex = zipWithIndex capture in
    let captureFiltr = List.fold_left (fun a c -> removeIndexed a c) captureIndex args in
    let captureParam = zip captureFiltr params in
    let _ = (List.iter 
                (fun ((_, currIndex), p) ->
                    (* assign the argument to the member of the struct *)
                    ignore(llvmAssignMember allocd_struct p currIndex builder)
                ) captureParam) in

    (* load structure, cast it to void*, return it *)
    let struct_load = L.build_load allocd_struct "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load voidptr "struct_cast" builder in
    ignore(L.build_ret struct_cast builder);
    fn_init

(* similar to the fix operator: enables recursion *)
and fix (name : string) arg lambdaName typEnv body = 
    let dummyScheme = Scheme([], (Concrete "Int")) in
    let capture = (M.fold (fun k _ acc -> k :: acc) 
                   (M.add arg dummyScheme typEnv) 
                   []) in

(*---------------------------------------------------------------------------*)  
    (* define the structure associated with this function *)
    let structT = L.named_struct_type context ("struct." ^ mangleEnv name) in
    let strptrT = L.pointer_type structT in
    let _ = L.struct_set_body structT
                         (Array.append 
                             (Array.of_list [funcptr]) 
                             (Array.make (List.length capture) voidptr))
                         false in

(*---------------------------------------------------------------------------*)  
    (* define the call function and allocate space for params *)
    let (fn_app, builder, params) = llvmFuncDef (mangleApp name) 
                        (List.append ["f"] (remove arg capture)) in
    let (f, params) = 
        (match params with
         | (f :: params) -> (f, params)
         | _ -> assert false)
    in

    (* malloc structure and cast it *)
    let allocd_struct = L.build_alloca strptrT "env" builder in
    let space = L.build_malloc structT "space" builder in
    let _ = L.build_store space allocd_struct builder in
    
    (* store function arguments into structure *)
    let captureIndex = zipWithIndex capture in
    let captureFiltr = removeIndexed captureIndex arg in
    let captureParam = zip captureFiltr params in
    let _ = (List.iter 
                (fun ((_, currIndex), p) ->
                    (* assign the argument to the member of the struct *)
                    ignore(llvmAssignMember allocd_struct p currIndex builder);
                ) captureParam) in

    (* NULL assignment *)
    let argIndex = 1 + find arg capture in
    let nullvar = L.build_alloca voidptr "_nullvar" builder in
    let _ = L.build_store (L.const_null voidptr) nullvar builder in
    let _ = llvmAssignMember allocd_struct nullvar argIndex builder in

    (* insert body of the call function *)
    let (e, te) = body in
    let { var  = evar; 
          lvar = elvar; } = check e te allocd_struct builder in

    (* make the struct self-referential *)
    let _ = llvmAssignMember elvar elvar
                             (if not (M.mem lambdaName te)
                              then 1 + argIndex
                              else argIndex) builder in

    (* call apply function *)
    let apply = applyFunc in
    let local = L.build_alloca voidptr "_tmp" builder in
    let fload = L.build_load f "_fload" builder in
    let eload = L.build_load elvar "_eload" builder in
    let call = L.build_call apply [|fload; eload|] "call" builder in
    let _ = L.build_store call local builder in

    (* return result *)
    let retval = L.build_load local "_ret" builder in
    let _ = L.build_ret retval builder in

    fn_app

and check (sexpr : sExpr)          (* expression to translate *)
          (typEnv : typeEnvironm)  (* type environment *)
          (llvmEnv : L.llvalue)    (* llvalue of type "env" *)
          (builder : L.llbuilder)  (* builder where to insert this *)
          : codegenResult =
  let (_, expr) = sexpr in
  match expr with
  | SVar (s)             -> 
          let var = "_" ^ (nextEntry lastTemp) in
          let ordered = (M.fold (fun k _ acc -> k :: acc) typEnv []) in
          let index = find s ordered in
          
          (* allocate space for result *)
          let local = L.build_alloca voidptr var builder in
          (* load structure, cast it, index into it *)
          let struct_load = L.build_load llvmEnv "struct_load" builder in
          let struct_cast = L.build_bitcast struct_load 
                                            voidptrptr "struct_cast" builder in
          let elem_ptr    = L.build_in_bounds_gep struct_cast
                                                  [| L.const_int i64_t (1 + index) |]
                                                  "elem_ptr" builder in
          let elem_load   = L.build_load elem_ptr "elem_load" builder in
          (* store result in allocd space *)
          let _ = L.build_store elem_load local builder in

          { var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SUnitLit             ->
          let var = "_" ^ (nextEntry lastTemp) in

          (* create a new var that stores the NULL pointer *)
          let local = L.build_alloca voidptr var builder in
          let const = L.build_inttoptr (L.const_int i64_t 0) 
                                       voidptr
                                       "const" builder in
          let _ = L.build_store const local builder in

          { var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SIntLit (i)          ->
          let var = "_" ^ (nextEntry lastTemp) in

          (* create a new var that stores the int casted to void* *)
          let local = L.build_alloca voidptr var builder in
          let const = L.build_inttoptr (L.const_int i64_t i) 
                                       voidptr
                                       "const" builder in
          let _ = L.build_store const local builder in

          { var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SFloatLit (i)       ->
          let var = "_" ^ (nextEntry lastTemp) in

          (* cast double to int *)
          let const_intr = L.build_fptosi (L.const_float float_t i)
                                          i64_t
                                          "const" builder in
          
          (* create a new var that stores this int casted to void * *)
          let local = L.build_alloca voidptr var builder in
          let const = L.build_inttoptr const_intr
                                       voidptr
                                       "const" builder in

          let _ = L.build_store const local builder in
          {
              var   = var;
              lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SCharLit (i)          ->
          let var = "_" ^ (nextEntry lastTemp) in

          (* create a new var that stores the int casted to void* *)
          let local = L.build_alloca voidptr var builder in
          let const = L.build_inttoptr (L.const_int i64_t i) 
                                       voidptr
                                       "const" builder in
          let _ = L.build_store const local builder in

          { var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SBoolLit (b)         ->
          let var = "_" ^ (nextEntry lastTemp) in

          (* create a new var that stores the bool casted to void* *)
          let local = L.build_alloca voidptr var builder in
          let const = L.build_inttoptr (L.const_int i64_t b) 
                                       voidptr
                                       "const" builder in
          let _ = L.build_store const local builder in

          { var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SListLit (lst)         ->
          let var = "_" ^ (nextEntry lastTemp) in
          let elems = List.map (fun e -> let { var = var;
                                               lvar = lvar; } = 
                                                   check e typEnv llvmEnv builder in 
                                         let elem = L.build_load lvar "_load" builder in
                                         let heapd = L.build_malloc voidptr "_heapd" builder in
                                         let _ = L.build_store elem heapd builder in
                                         { var = var;
                                           lvar = heapd; }) lst in
          let n = List.length lst in
          let local = L.build_array_malloc voidptr (L.const_int i64_t (2*(n + 1))) var builder in

          (* store null pointer in local *)
          let nullp' = (L.const_null i64_t) in
          let nullp = L.build_pointercast nullp' voidptr "_null" builder in

          let linkList a b = 
              let (sptr, nptr) = b in
              let sptr'   = L.build_gep sptr [|(L.const_int i64_t 1)|] "" builder in
              let sptr''  = L.build_gep sptr [|(L.const_int i64_t 2)|] "" builder in
              let avptr = L.build_pointercast a.lvar voidptr "_avptr" builder in
              let nvptr = L.build_pointercast nptr voidptr "_nvptr" builder in
              let _ = L.build_store avptr sptr builder in
              let _ = L.build_store nvptr sptr' builder in
              (sptr'', sptr)
          in
          let (_, sptr) = List.fold_right linkList elems (local, nullp) in
          let local' = L.build_alloca voidptr var builder in
          let sptr' = L.build_pointercast sptr voidptr "" builder in
          let _ = L.build_store sptr' local' builder in

          { var   = var;
            lvar  = local';
          }
(*---------------------------------------------------------------------------*)  
  | SBinop (b, e, f)     ->
    let { var   = evar; 
          lvar  = elvar; } = check e typEnv llvmEnv builder in
    let { var   = fvar; 
          lvar  = flvar; } = check f typEnv llvmEnv builder in
    let var = "_" ^ (nextEntry lastTemp) in

    (* load vars and cast them to long long *)
    let eload = L.build_load elvar "_eload" builder in
    let ecast = L.build_ptrtoint eload i64_t "_ecast" builder in

    let fload = L.build_load flvar "_fload" builder in
    let fcast = L.build_ptrtoint fload i64_t "_fcast" builder in
    
    (* apply binary operator and store result *)
    let local = L.build_alloca voidptr var builder in
    let res = (match b with
              | ADD -> L.build_add  ecast fcast "_res" builder
              | SUB -> L.build_sub  ecast fcast "_res" builder
              | MLT -> L.build_mul  ecast fcast "_res" builder
              | DIV -> L.build_sdiv ecast fcast "_res" builder
              | MOD -> L.build_srem ecast fcast "_res" builder
              | AND -> L.build_and  ecast fcast "_res" builder
              | OR  -> L.build_or   ecast fcast "_res" builder
              | EQ  -> L.build_icmp L.Icmp.Eq ecast fcast "_res" builder
              | LT  -> L.build_icmp L.Icmp.Slt ecast fcast "_res" builder
              | LTE -> L.build_icmp L.Icmp.Sle ecast fcast "_res" builder
              | GT  -> L.build_icmp L.Icmp.Sgt ecast fcast "_res" builder
              | GTE -> L.build_icmp L.Icmp.Sge ecast fcast "_res" builder
              ) in
    let rescast = L.build_inttoptr res voidptr "_rescast" builder in
    let _ = L.build_store rescast local builder in

    { var  = var;
      lvar = local;
    }
(*---------------------------------------------------------------------------*)  
  | SLCons (e, f)    ->
    let { var   = evar; 
          lvar  = elvar; } = check e typEnv llvmEnv builder in
    let { var   = fvar; 
          lvar  = flvar; } = check f typEnv llvmEnv builder in
    let var = "_" ^ (nextEntry lastTemp) in

    let local = L.build_array_malloc voidptr (L.const_int i64_t 2) var builder in

    let elem = L.build_load elvar "_elem" builder in
    let heapd = L.build_malloc voidptr "_heapd" builder in
    let _ = L.build_store elem heapd builder in 
    let avptr = L.build_pointercast heapd voidptr "_avptr" builder in
    let _ = L.build_store avptr local builder in

    let sptr  = L.build_gep local [|(L.const_int i64_t 1)|] "_sptr" builder in
    let fload = L.build_load flvar "" builder in
    let flptr = L.build_pointercast fload voidptr "_avptr" builder in
    let _     = L.build_store flptr sptr builder in
              
    let resptr = L.build_alloca voidptr "" builder in
    let res = L.build_pointercast local voidptr "" builder in
    let _ = L.build_store res resptr builder in

    { var  = var;
      lvar = resptr;
    }
(*---------------------------------------------------------------------------*)  
  | SLLen (e)    ->
    let { var   = evar; 
          lvar  = elvar; } = check e typEnv llvmEnv builder in
    let var = "_" ^ (nextEntry lastTemp) in
    let lenfunc = lenFunc in

    let eptr = L.build_pointercast elvar voidptrptr "_eeeeptr" builder in 
    (* cast to void** for some reason *)
    let loadeptr = L.build_load eptr "_loadddddd" builder in
    let xptr = L.build_inttoptr loadeptr voidptr "_xptrdddd" builder in 
    (* cast to void** for some reason *)
    (* result stuff *)
    let local = L.build_alloca voidptr var builder in
    let call = L.build_call lenfunc [|xptr|] "callddd" builder in
    let _ = L.build_store call local builder in

    { var  = var;
      lvar = local;
    }
(*---------------------------------------------------------------------------*)  
  | SUnop (b, e)     ->
    let { var   = evar; 
          lvar  = elvar; } = check e typEnv llvmEnv builder in
    let var = "_" ^ (nextEntry lastTemp) in

    (* load var and cast it to long long *)
    let eload = L.build_load elvar "_eload" builder in
    let ecast = L.build_ptrtoint eload i64_t "_ecast" builder in

    (* apply unary operator and store result *)
    let local = L.build_alloca voidptr var builder in
    let res = (match b with
              | NOT -> L.build_not  ecast "_res" builder
              ) in
    let rescast = L.build_inttoptr res voidptr "_rescast" builder in
    let _ = L.build_store rescast local builder in
    
    { var  = var;
      lvar = local;
    }
(*---------------------------------------------------------------------------*)  
  | SIf (c, t, e)     ->
    (* generate code that produces the condition,
       the then value (wrapped in a lambda) and
       the else value (wrapped in a lambda) *)
    let { var   = cvar; 
          lvar  = clvar; } = check c typEnv llvmEnv builder in
    let { var   = tvar; 
          lvar  = tlvar; } = check t typEnv llvmEnv builder in
    let { var   = evar; 
          lvar  = elvar; } = check e typEnv llvmEnv builder in

    let var = "_" ^ (nextEntry lastTemp) in
    (* allocate space for result *)
    let local = L.build_alloca voidptr var builder in

    let _if = ifFunc in
    
    (* call apply function and store result in llvalue *)
    let cload = L.build_load clvar "_cload" builder in
    let tload = L.build_load tlvar "_tload" builder in
    let eload = L.build_load elvar "_eload" builder in
    let call = L.build_call _if [|cload; tload; eload|] "call" builder in
    let _ = L.build_store call local builder in

    { var  = var;
      lvar = local;
    }
(*---------------------------------------------------------------------------*)  
  | SLambda (LVar(v), e) -> 
          let name = nextEntry lastClass in
          let typEnvNew = M.add v (Scheme([], Concrete "Int")) typEnv in
          
          (* generate the code for the structure,
             its constructor and its call operator *)
          let llvm_init = cppfunction name v (e, typEnvNew) typEnv in
          
          (* instantiate the function structure *)
          let var = "_" ^ (nextEntry lastTemp) in
          let lvar = cppfunctioninst var name llvm_init v typEnv llvmEnv builder in
          { var   = var;
            lvar  = lvar;
          }
(*---------------------------------------------------------------------------*)  
  | SCall (f, arg)       -> 
          (* generate the code that produces the function *)
          let { var   = fvar; 
                lvar  = flvar; } = check f typEnv llvmEnv builder in 
          (* generate the code that produces the argument *)
          let { var   = argvar; 
                lvar  = arglvar; } = check arg typEnv llvmEnv builder in
          (* call apply on the function and the argument *)
          let var = "_" ^ (nextEntry lastTemp) in
          let local = callApply var 
                                fvar flvar 
                                argvar arglvar 
                                builder in

          { var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SLet (SBinding(LVar(v), e, false), f) ->
          let name = nextEntry lastClass in
          let typEnvNew = M.add v (Scheme([], Concrete "Int")) typEnv in
          
          (* let v = e in f ---> (\v -> f)(e) *)
          (* generate the code for the structure,
             its constructor and its call operator *)
          let llvm_init = cppfunction name v (f, typEnvNew) typEnv in
          
          (* generate the code that produces e *)
          let { var   = evar; 
                lvar  = elvar; } = check e typEnv llvmEnv builder in

          (* instantiate the function structure with capture *)
          let tmp = "_" ^ (nextEntry lastTemp) in
          let ltmp = cppfunctioninst tmp name llvm_init v typEnv llvmEnv builder in
          
          (* apply e to the function *)
          let var = "_" ^ (nextEntry lastTemp) in
          let local = callApply var 
                                tmp ltmp 
                                evar elvar  (* argvar arglvar *) 
                                builder in

          { var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SLet (SBinding(LVar(v), e, _), f)  ->
        let w = (match e with
                 | (_, SLambda(LVar(w), _)) -> w
                 | _ -> assert false)
        in
        let name = nextEntry lastClass in
        let typEnvNew = M.add v (Scheme ([], Concrete "Int")) typEnv in

        let llvm_init = cppfunction name v (f, typEnvNew) typEnv in
        let llvm_app = fix name v w typEnv (e, typEnvNew) in
        
        (* special code generation for recursive let-bindings *)
        let tmp = "_" ^ (nextEntry lastTemp) in
        let ltmp = cppfunctioninst tmp name llvm_init v typEnv llvmEnv builder in

        (* allocate space for result *)
        let var = "_" ^ (nextEntry lastTemp) in
        let local = L.build_alloca voidptr var builder in

        (* call apply function and store result *)
        let tmpload = L.build_load ltmp "_tmpload" builder in
        let llvmArgs = [tmpload] @ (loadEnvExcept typEnv llvmEnv v builder) in
        let call = L.build_call llvm_app (Array.of_list llvmArgs) "call" builder in
        let _ = L.build_store call local builder in

        { var   = var;
          lvar  = local;
        }
 | SLet (SCBinding(lhs, e), f) ->
          let name = nextEntry lastClass in
          let vlist = List.map (fun (LVar v) -> v) lhs in 
          let rec addAllArgs m vars =
              match vars with
              | v::vs -> addAllArgs (M.add v (Scheme([], Concrete "Int")) m) vs
              | _     -> m
          in 
          let typEnvNew = addAllArgs typEnv vlist in
          (* let v = e in f ---> (\v -> f)(e) *)
          (* generate the code for the structure,
             its constructor and its call operator *)
          let llvm_init = cppCfunction name vlist (f, typEnvNew) typEnv in
          
          (* generate the code that produces e *)
          let { var   = evar; 
                lvar  = elvar; } = check e typEnv llvmEnv builder in

          (* instantiate the function structure with capture *)
          let tmp = "_" ^ (nextEntry lastTemp) in
          let ltmp  = cppCfunctioninst tmp name llvm_init vlist typEnv llvmEnv builder in
          
          (* apply e to the function *)
          let var = "_" ^ (nextEntry lastTemp) in
          let local = callApply var 
                                tmp ltmp 
                                evar elvar  (* argvar arglvar*) 
                                builder in

          { var   = var;
            lvar  = local;
          }
 | SLet (SMBinding(lhs, e), f) ->
          let name = nextEntry lastClass in
          let vlist = List.map (fun (LVar v) -> v) lhs in 
          let rec addAllArgs m vars =
              match vars with
              | v::vs -> addAllArgs (M.add v (Scheme([], Concrete "Int")) m) vs
              | _     -> m
          in 
          let typEnvNew = addAllArgs typEnv vlist in
          (* let v = e in f ---> (\v -> f)(e) *)
          (* generate the code for the structure,
             its constructor and its call operator *)
          let llvm_init = cppMfunction name vlist (f, typEnvNew) typEnv in
          
          (* generate the code that produces e *)
          let { var   = evar; 
                lvar  = elvar; } = check e typEnv llvmEnv builder in

          (* instantiate the function structure with capture *)
          let tmp = "_" ^ (nextEntry lastTemp) in
          let ltmp  = cppCfunctioninst tmp name llvm_init vlist typEnv llvmEnv builder in
          
          (* apply e to the function *)
          let var = "_" ^ (nextEntry lastTemp) in
          let local = callApply var 
                                tmp ltmp 
                                evar elvar  (* argvar arglvar*) 
                                builder in

          { var   = var;
            lvar  = local;
          }

(*---------------------------------------------------------------------------*)  
 | SPrint(e) -> 
    (* construct the List Char *)
    let { var  = evar;
          lvar = elvar; } = check e typEnv llvmEnv builder in

    let var = "_" ^ (nextEntry lastTemp) in
    let printfunc = printFunc in

    let eptr = L.build_pointercast elvar voidptrptr "_eeeeptr" builder in 
    (* cast to void** for some reason *)
    let loadeptr = L.build_load eptr "_loadddddd" builder in
    let xptr = L.build_inttoptr loadeptr voidptr "_xptrdddd" builder in 
    (* cast to void** for some reason *)
    (* result stuff *)
    let local = L.build_alloca voidptr var builder in
    let call = L.build_call printfunc [|xptr|] "callddd" builder in
    let _ = L.build_store call local builder in

    { var  = var;
      lvar = local;
    }
(*---------------------------------------------------------------------------*)    
 | SOrd(e) -> 
    (* construct the List Char *)
    check e typEnv llvmEnv builder
 | SChr(e) -> 
    (* construct the List Char *)
    check e typEnv llvmEnv builder
