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
let applyFunc : (L.llvalue *   (* llvalue of the apply function *)
                 string) =     (* C code associated with it *)
    (* function signature and param space *)
    let (func, builder, f :: arg :: []) = 
        llvmFuncDef "apply" ["f"; "arg"] in

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

    (* C code generation *)
    (func, 
    "void* apply(void* f, void* arg){\n\
         \treturn (**((void* (**)(void*, void*)) f))(f, arg);\n\
     }\n")

(* generate a call to the `apply` function with arguments f and arg *)
let callAppSp (var : string)          (* name of result *)
              (local : L.llvalue)     (* llvalue of result *)
              (fvar : string)         (* name of function *)
              (flvar : L.llvalue)     (* llvalue of function *)
              (argvar : string)       (* name of argument *)
              (arglvar : L.llvalue)   (* llvalue of argument *)
              (builder : L.llbuilder) (* builder where to insert this *)
              : string =              (* C code *)
    let (apply, _) = applyFunc in
    
    (* call apply function and store result in llvalue *)
    let fload = L.build_load flvar "_fload" builder in
    let argload = L.build_load arglvar "_argload" builder in
    let call = L.build_call apply [|fload; argload|] "call" builder in
    let _ = L.build_store call local builder in

    "\t" ^ var ^ " = apply(" ^ fvar ^ ", " ^ argvar ^ ");\n"
(* generate a call to the `apply` function with arguments f and arg *)
let callApply (var : string)          (* name of result *)
              (fvar : string)         (* name of function *)
              (flvar : L.llvalue)     (* llvalue of function *)
              (argvar : string)       (* name of argument *)
              (arglvar : L.llvalue)   (* llvalue of argument *)
              (builder : L.llbuilder) (* builder where to insert this *)
              : (L.llvalue *          (* llvalue of result *)
                 string) =            (* C code *)
    (* call apply function and store result in llvalue *)
    let local = L.build_alloca voidptr var builder in
    let code = callAppSp var local 
                         fvar flvar 
                         argvar arglvar 
                         builder in
    (local, 
    "\tvoid* " ^ var ^ ";\n" ^ code)

(* function that performs function application *)
let ifFunc : (L.llvalue *   (* llvalue of the if function *)
              string) =     (* C code associated with it *)
    (* function signature and param space *)
    let (func, builder, c :: t :: e :: []) = 
        llvmFuncDef "_if" ["c"; "t"; "e"] in

    let nullvar = L.build_alloca voidptr "_nullvar" builder in
    let _ = L.build_store (L.const_null voidptr) nullvar builder in

    (* then block *)
    let then_bb = L.append_block context "then" func in
    let then_b = L.builder_at_end context then_bb in
    let (res, then_assign) = callApply "_res"
                                       "t" t 
                                       "NULL" nullvar
                                       then_b in
    let loadres = L.build_load res "_loadres" then_b in
    let _ = L.build_ret loadres then_b in

    (* else block *)
    let else_bb = L.append_block context "else" func in
    let else_b = L.builder_at_end context else_bb in
    let (res, else_assign) = callApply "_res"
                                       "e" e
                                       "NULL" nullvar
                                       else_b in
    let loadres = L.build_load res "_loadres" else_b in
    let _ = L.build_ret loadres else_b in
    
    (* branch *)
    let loadc = L.build_load c "_loadc" builder in
    let boolc = L.build_icmp L.Icmp.Eq loadc (L.const_null voidptr) "_res" builder in
    let _ = L.build_cond_br boolc else_bb then_bb builder in

    (* C code generation *)
    (func, 
    "void* _if(void* c, void* t, void* e){\n\
         \tif(c){\n\
         \t" ^ then_assign ^ "\
         \t\t return _res;\n\
         \t}\n\
         \telse{\n\
         \t" ^ else_assign ^ "\
         \t\t return _res;\n\
         \t}\n\
     }\n")

(* fixed includes and classes *)
let prelude (typEnv : typeEnvironm) : string = 
    let (_, applyCode) = applyFunc in
    let (_, ifCode) = ifFunc in
    "#include<stdio.h>\n\
     #include <stdlib.h>\n" ^
    applyCode ^
    ifCode
    
let buildPrimitiveEnv : (string * typeEnvironm) = 
  let m = M.empty in
  (prelude m, m)

(* find the index of an element in a list *)
let find x ys = 
    let rec helper x index = function
    |  []     -> raise(Failure("impossible"))
    | y :: ys -> if x = y then index
                          else helper x (index + 1) ys
    in helper x 0 ys

(* instantiate a class corresponding to a function *)
let cppfunctioninst (var : string)           (* the varname of the result *)
                    (name : string)          (* the name of the function  *)
                    (llvm_init : L.llvalue)  (* the llvalue of its init function *)
                    (arg : string)           (* the name of the argument *)
                    (typEnv : typeEnvironm)  (* the type environment *)
                    (llvmEnv : L.llvalue)    (* llvalue of the "env" *)
                    (builder : L.llbuilder)  (* builder where to insert this *)
                    : (L.llvalue *           (* llvalue of the result *)
                       string) =             (* C code *)
    let capture = (M.fold (fun k _ acc -> k :: acc) typEnv []) in
    let currIndex = ref 0 in
    let assigns = 
            List.fold_left 
              (^) ""
              (List.map (fun v -> (
                  currIndex := !currIndex + 1;
                  if v = arg then ""
                  else
                    ", *((void** ) env + " ^ (string_of_int !currIndex) ^ ")")) 
              capture) in
    
    (* prepare call arguments *)
    let currIndex = ref 0 in
    let llvmArgs = 
                (List.fold_left 
                (fun acc v ->
                    currIndex := !currIndex + 1;
                    if v = arg 
                    then acc
                    else
                        let var = "_" ^ (nextEntry lastTemp) in
                        (* load structure, cast it, index into it *)
                        let struct_load = L.build_load llvmEnv "struct_load" builder in
                        let struct_cast = L.build_bitcast struct_load 
                                                  voidptrptr "struct_cast" builder in
                        let elem_ptr    = L.build_in_bounds_gep struct_cast
                                                  [| L.const_int i64_t (!currIndex) |]
                                                  "elem_ptr" builder in
                        (* load the result to be passed to the init call *)
                        let load = L.build_load elem_ptr (var ^ "_load") builder in

                        acc @ [load]
                )
                []
                capture) in
 
    (* call the llvm_init function with the llvmargs *)
    let local = L.build_alloca voidptr var builder in
    let call = L.build_call llvm_init (Array.of_list llvmArgs) "call" builder in
    let _ = L.build_store call local builder in

    (* C code generation *)
    let arg = if String.length assigns > 0 
              then String.sub assigns 2 (String.length assigns - 2)
              else assigns in
    
    (local, 
         "\tvoid* " ^ var ^ " = " ^ (mangleInit name) ^ 
            "(" ^ arg  ^ ");\n"
    )

(* generates the C code for a function;     
   acts essentially as a lambda function written in C: each function has a
   unique corresponding class with its call operator and its capture *)
let rec cppfunction (name : string)           (* name of the function *)
                    (arg : string)            (* argument name *)
                    (body : (sExpr *          (* sExpr of function body *)
                             typeEnvironm))   (* env to evaluate the body in *)
                    (typEnv : typeEnvironm)   (* the type environment *)
                    : (L.llvalue *            (* llvalue of the init function *)
                       string) =              (* C code *)
    let dummyScheme = Scheme([], (Concrete "Int")) in
    let capture = (M.fold (fun k _ acc -> k :: acc) 
                   (M.add arg dummyScheme typEnv) 
                   []) in
    let ccapture = sep ", *" capture in
    let vcapture = sep ", void* " (remove arg capture) in
    let vcapture = if (String.length vcapture) > 0 
                   then "void* " ^ vcapture 
                   else vcapture in

    let currIndex = ref 0 in
    let argIndex = ref 0 in
    let assigns = 
            List.fold_left 
              (^) ""
              (List.map (fun v -> (
                  currIndex := !currIndex + 1;
                  if v = arg then (
                      argIndex := !currIndex;
                      ""
                  )
                  else
                    "\t*((void** ) reserved + " ^ (string_of_int !currIndex) ^ 
                    ") = " ^ v ^ ";\n")) capture) in

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
    
    let (llvm_genenv :: llvm_arg :: []) = params in

    (* cast struct *)
    let allocd_struct = L.build_alloca strptrT "env" builder in
    let struct_load = L.build_load llvm_genenv "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load strptrT "struct_cast" builder in
    let _ = L.build_store struct_cast allocd_struct builder in

    (* store argument in "capture" *)
    let _ = llvmAssignMember allocd_struct llvm_arg (!argIndex) builder in

    (* insert the body of the call function *)
    let (e, te) = body in
    let { code  = code; 
          var   = evar;
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
    let currIndex = ref 0 in
    let currParam = ref params in
    let _ = (List.iter 
                (fun v ->
                    currIndex := !currIndex + 1;
                    if v = arg 
                    then ()
                    else
                        let (p :: ps) = !currParam in
                        (* assign the argument to the member of the struct *)
                        let _ = llvmAssignMember allocd_struct p !currIndex builder in
                        currParam := ps;
                )
                capture) in

    (* load structure, cast it to void*, return it *)
    let struct_load = L.build_load allocd_struct "struct_load" builder in
    let struct_cast = L.build_bitcast struct_load voidptr "struct_cast" builder in
    ignore(L.build_ret struct_cast builder);
    
(*---------------------------------------------------------------------------*)  
    (* C code generation *)
    (fn_init, 
    "struct " ^ (mangleName name) ^ "{\n\
         \tvoid* (*call)(void*, void*);\n\
         \tvoid *" ^ ccapture ^ ";\n\
     };\n\
     void* " ^ (mangleCall name) ^ "(void* genenv, void* " ^ arg ^ "){\n\
         \tstruct " ^ (mangleName name) ^ 
                 " *env = (struct " ^ (mangleName name) ^ "* ) genenv;\n\
         \t*((void** ) env + " ^ (string_of_int (!argIndex)) ^ ") = " ^ arg ^ ";\n"
             ^ code ^ 
         "\treturn " ^ evar ^ ";\n\
     }\n\
     void* " ^ (mangleInit name) ^ "("^ vcapture ^ "){\n\
        \tstruct " ^ (mangleName name) ^ "* reserved = \
            (struct " ^ (mangleName name) ^ "*)malloc(sizeof(*reserved));\n\
        \t*(void* (**) (void*, void* )) reserved = &" ^ (mangleCall name) ^ ";\n" ^
        assigns ^ 
        "\treturn (void* ) reserved;\n\
     }\n"
    )

(* similar to the fix operator: enables recursion *)
and fix name arg lambdaName typEnv body = 
    let dummyScheme = Scheme([], (Concrete "Int")) in
    let capture = (M.fold (fun k _ acc -> k :: acc) 
                   (M.add arg dummyScheme typEnv) 
                   []) in
    let ccapture = sep ", *" capture in
    let vcapture = sep ", void *" (remove arg capture) in
    let vcapture = if String.length vcapture > 0
                   then ", void*" ^ vcapture
                   else vcapture
    in

    let currIndex = ref 0 in
    let argIndex = ref 0 in
    let assigns = 
            List.fold_left 
              (^) ""
              (List.map (fun v -> (
                  currIndex := !currIndex + 1;
                  if v = arg then (
                      argIndex := !currIndex;
                      ""
                  )
                  else
                    "\t*((void** ) env + " ^ (string_of_int !currIndex) ^ 
                    ") = " ^ v ^ ";\n")) capture) in

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
    let (f :: params) = params in

    (* malloc structure and cast it *)
    let allocd_struct = L.build_alloca strptrT "env" builder in
    let space = L.build_malloc structT "space" builder in
    let _ = L.build_store space allocd_struct builder in
    
    (* store function arguments into structure *)
    let currIndex = ref 0 in
    let currParam = ref params in
    let _ = (List.iter 
                (fun v ->
                    currIndex := !currIndex + 1;
                    if v = arg 
                    then ()
                    else
                        let (p :: ps) = !currParam in
                        (* assign the argument to the member of the struct *)
                        let _ = llvmAssignMember allocd_struct p !currIndex builder in
                        currParam := ps;
                )
                capture) in
    
    (* NULL assignment *)
    let _ = llvmAssignMember allocd_struct (L.const_null voidptr) (!argIndex) builder in

    (* insert body of the call function *)
    let (e, te) = body in
    let { code = codee;
          var  = evar; 
          lvar = elvar; } = check e te allocd_struct builder in

    (* make the struct self-referential *)
    let _ = llvmAssignMember elvar elvar
                             (if not (M.mem lambdaName te)
                              then 1 + !argIndex
                              else !argIndex) builder in

    (* call apply function *)
    let (apply, _) = applyFunc in
    let local = L.build_alloca voidptr "_tmp" builder in
    let fload = L.build_load f "_fload" builder in
    let eload = L.build_load elvar "_eload" builder in
    let call = L.build_call apply [|fload; eload|] "call" builder in
    let _ = L.build_store call local builder in

    (* return result *)
    let retval = L.build_load local "_ret" builder in
    let _ = L.build_ret retval builder in

(*---------------------------------------------------------------------------*)  
     (* C code generation *)
     "struct " ^ mangleEnv name ^ "{\n\
          \t void* (*call) (void*, void*);\n\
          \tvoid *" ^ ccapture ^ ";\n\
      };\n\
      void* " ^ mangleApp name ^ "(void* f" ^ vcapture ^ "){\n\
          \tstruct " ^ mangleEnv name ^ "* env = malloc(sizeof(*env));\n"
          ^ assigns ^
         "\t*((void**) env + " ^ (string_of_int (!argIndex)) ^ ") = NULL;\n"
          ^ codee   ^ 
         "\t*(void** )(" ^ evar ^ " + " 
                 (*^ string_of_int (1 + List.length capture) ^*)
                 ^ string_of_int (if not (M.mem lambdaName te)
                                 then 1 + !argIndex
                                 else !argIndex) ^
                 " * sizeof(void* )) = " ^ evar ^ ";\n\
          \treturn apply(f, " ^ evar ^ ");\n\
      }\n"

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

              { code  = "\tvoid* " ^ var ^ 
                        " = (*((void**) env + " ^ string_of_int (1 + index) ^ "));\n";
                var   = var;
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

          { code  = "\tvoid* " ^ var ^ " = ((void* ) " ^ string_of_int i ^ ");\n";
            var   = var;
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

          { code  = "\tvoid* " ^ var ^ " = ((void* ) " ^ string_of_int b ^ ");\n";
            var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SBinop (b, e, f)     ->
    let { code  = codee; 
          var   = evar; 
          lvar  = elvar; } = check e typEnv llvmEnv builder in
    let { code  = codef;
          var   = fvar; 
          lvar  = flvar; } = check f typEnv llvmEnv builder in
    let sym = (match b with
              | ADD -> "+"
              | SUB -> "-"
              | MLT -> "*"
              | DIV -> "/"
              | MOD -> "%"
              | AND -> "&&"
              | OR  -> "||"
              | EQ  -> "==") in
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
              ) in
    let rescast = L.build_inttoptr res voidptr "_rescast" builder in
    let _ = L.build_store rescast local builder in

    { code = codee ^ 
             codef ^ 
	         "\tvoid* " ^ var ^ " = (void* ) ((long long)((long long) " ^ evar ^ " " 
                        ^ sym ^ " (long long) " ^ fvar ^ "));\n";
      var  = var;
      lvar = local;
    }
(*---------------------------------------------------------------------------*)  
  | SUnop (b, e)     ->
    let { code  = codee; 
          var   = evar; 
          lvar  = elvar; } = check e typEnv llvmEnv builder in
    let sym = match b with
              | NOT -> "!" in
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
    
    { code = codee ^ 
             "\tvoid* " ^ var ^ 
                        " = (void* )((long long)" ^ sym ^ "((long long) " ^ evar ^ "));\n";
      var  = var;
      lvar = local;
    }
(*---------------------------------------------------------------------------*)  
  | SIf (c, t, e)     ->
    let { code  = codec; 
          var   = cvar; 
          lvar  = clvar; } = check c typEnv llvmEnv builder in
    let { code  = codet; 
          var   = tvar; 
          lvar  = tlvar; } = check t typEnv llvmEnv builder in
    let { code  = codee; 
          var   = evar; 
          lvar  = elvar; } = check e typEnv llvmEnv builder in

    let var = "_" ^ (nextEntry lastTemp) in
    (* allocate space for result *)
    let local = L.build_alloca voidptr var builder in

    let (_if, _) = ifFunc in
    
    (* call apply function and store result in llvalue *)
    let cload = L.build_load clvar "_cload" builder in
    let tload = L.build_load tlvar "_tload" builder in
    let eload = L.build_load elvar "_eload" builder in
    let call = L.build_call _if [|cload; tload; eload|] "call" builder in
    let _ = L.build_store call local builder in

    { code = codec ^
             codet ^
             codee ^
             "\tvoid* " ^ var ^ " = _if(" ^ cvar ^ ", " ^ tvar ^ ", " ^ evar ^");\n";
      var  = var;
      lvar = local;
    }
(*---------------------------------------------------------------------------*)  
  | SLambda (LVar(v), e) -> 
          let name = nextEntry lastClass in
          let typEnvNew = M.add v (Scheme([], Concrete "Int")) typEnv in

          let (llvm_init, func_snippet) = cppfunction name v (e, typEnvNew) typEnv in
          classes := !classes ^ func_snippet;

          let var = "_" ^ (nextEntry lastTemp) in
          let (lvar, inst_snippet) = 
               cppfunctioninst var name llvm_init v typEnv llvmEnv builder in
          { code  = inst_snippet;
            var   = var;
            lvar  = lvar;
          }
(*---------------------------------------------------------------------------*)  
  | SCall (f, arg)       -> 
          let { code  = codef; 
                var   = fvar; 
                lvar  = flvar; } = check f typEnv llvmEnv builder in 
          let { code  = codearg;
                var   = argvar; 
                lvar  = arglvar; } = check arg typEnv llvmEnv builder in
          
          let var = "_" ^ (nextEntry lastTemp) in
          let (local, apply_snippet) = callApply var 
                                                 fvar flvar 
                                                 argvar arglvar 
                                                 builder in

          { code  = codef ^ codearg ^ apply_snippet;
            var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
  | SLet (SBinding(LVar(v), e, false), f) ->
          let name = nextEntry lastClass in
          let typEnvNew = M.add v (Scheme([], Concrete "Int")) typEnv in

          let (llvm_init, snippet) = cppfunction name v (f, typEnvNew) typEnv in
          classes := !classes ^ snippet;

          let { code  = codee; 
                var   = evar; 
                lvar  = elvar; } = check e typEnv llvmEnv builder in

          let tmp = "_" ^ (nextEntry lastTemp) in
          let (ltmp, inst_snippet) = 
                     cppfunctioninst tmp name llvm_init v typEnv llvmEnv builder in

          let var = "_" ^ (nextEntry lastTemp) in
          let (local, apply_snippet) = callApply var 
                                                 tmp ltmp 
                                                 evar elvar 
                                                 builder in

          let code = codee ^ inst_snippet ^ apply_snippet in
          { code  = code;
            var   = var;
            lvar  = local;
          }
(*---------------------------------------------------------------------------*)  
(*  | SLet (SBinding(LVar(v), e, _), f)  ->
        let w = (match e with
                 | (_, SLambda(LVar(w), _)) -> w
                 | _ -> raise(Failure("Impossible")))
        in
        let name = nextEntry lastClass in
        let typEnvNew = M.add v (Scheme ([], Concrete "Int")) typEnv in

        let (llvm_init, snippet) = cppfunction name v (f, typEnvNew) typEnv;
        classes := !classes ^ 
                   snippet ^
                   fix name v w typEnv (e, typEnvNew);

        
        (* special code generation for recursive let-bindings *)
        let capture = (remove v 
                      (M.fold (fun k _ acc -> k :: acc) typEnv [])) in
        let acapture = sep ", env->" capture in
        let acapture = if String.length acapture > 0 
                       then ", env->" ^ acapture
                       else acapture
        in
                    
        (* TODO *)
        let var = "_" ^ (nextEntry lastTemp) in
        let tmp = "_" ^ (nextEntry lastTemp) in
        let func = cppfunctioninst tmp name llvm_init v typEnv llvmEnv builder in
        { code  = func ^ 
                  "\tvoid* " ^ var ^ " = " ^ 
                       (mangleApp name) ^ "(" ^ tmp ^ acapture ^ ");\n";
          var   = var;
        }
*)
