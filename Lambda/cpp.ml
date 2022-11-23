open Unification
open Ast
module M = Map.Make(String)
module L = Llvm

let context    = L.global_context()
let the_module = L.create_module context "Orlang"
let i8_t       = L.i8_type context
let i32_t      = L.i32_type context
let voidptr    = L.pointer_type i8_t

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

(* general C skeleton for a unary function *)
let primitiveUnaryFunc (name : string) (sym : string) : string = 
    "\
     struct operator_" ^ name ^ "_cls{\n\
	     \tvoid* (*call)(void*, void*);\n\
	     \tvoid *x;\n\
     };\n\
     void* operator_" ^ name ^ "_call(void* genenv, void* x){\n\
	     \tstruct operator_" ^ name ^ 
                 "_cls *env = (struct operator_" ^ name ^ "_cls*) genenv;\n\
	     \tenv->x = x;\n\
         \treturn (void*)((long long)" ^ sym ^ "((long long) x));\n\
     }\n"

(* general C skeleton for a binary function *)
let primitiveBinaryFunc (name : string) (sym : string) : string = 
"\
struct poperator_" ^ name ^ "_cls{\n\
	\tvoid* (*call)(void*, void*);\n\
	\tvoid *x, *y;\n\
};\n\
void* poperator_" ^ name ^ "_call(void* genenv, void* y){\n\
	\tstruct poperator_" ^ name ^ "_cls *env = (struct poperator_" ^ name ^ "_cls*) genenv;\n\
	\tenv->y = y;\n\
	\treturn (void*) ((long long)((long long) env->x " ^ sym ^ " (long long) env->y));\n\
}\n\
struct operator_" ^ name ^ "_cls{\n\
	\tvoid* (*call)(void*, void*);\n\
	\tvoid *x;\n\
};\n\
void* operator_" ^ name ^ "_call(void* genenv, void* x){\n\
	\tstruct operator_" ^ name ^ "_cls *env = (struct operator_" ^ name ^ "_cls*) genenv;\n\
	\tenv->x = x;\n\
    \tstruct poperator_" ^ name ^ "_cls *reserved = (struct poperator_" ^ name ^ "_cls*) malloc(sizeof(*reserved));\n\
    \treserved->call = &poperator_" ^ name ^ "_call;\n\
    \treserved->x = env->x;\n\
	\treturn (void*) reserved;\n\
}\n"

(* C code for the if statement *)
let ifstatement : string = 
"struct ppoperator_if_cls{\n\
	\tvoid* (*call)(void*, void*);\n\
	\tvoid *y, *x, *z;\n\
};\n\
void* ppoperator_if_call(void* genenv, void* z){\n\
	\tstruct ppoperator_if_cls *env = (struct ppoperator_if_cls*) genenv;\n\
	\tenv->z = z;\n\
    \tif(env->x)\n\
    \t    return apply(env->y, NULL);\n\
    \treturn apply(env->z, NULL);\n\
}\n\
void* ppoperator_if_init(void* y, void* x){\n\
	\tstruct ppoperator_if_cls* reserved = \
        (struct ppoperator_if_cls*)malloc(sizeof(*reserved));\n\
	\treserved->call = &ppoperator_if_call;\n\
	\treserved->y = y;\n\
	\treserved->x = x;\n\
	\treturn (void*) reserved;\n\
}\n\
struct poperator_if_cls{\n\
	\tvoid* (*call)(void*, void*);\n\
	\tvoid *x, *y;\n\
};\n\
void* poperator_if_call(void* genenv, void* y){\n\
	\tstruct poperator_if_cls *env = (struct poperator_if_cls*) genenv;\n\
	\tenv->y = y;\n\
	\treturn ppoperator_if_init(env->y, env->x);\n\
}\n\
void* poperator_if_init(void* x){\n\
	\tstruct poperator_if_cls* reserved = (struct poperator_if_cls*)malloc(sizeof(*reserved));\n\
	\treserved->call = &poperator_if_call;\n\
	\treserved->x = x;\n\
	\treturn (void*) reserved;\n\
}\n\
struct operator_if_cls{\n\
	\tvoid* (*call)(void*, void*);\n\
	\tvoid *x;\n\
};\n\
void* operator_if_call(void* genenv, void* x){\n\
	\tstruct operator_if_cls *env = (struct operator_if_cls*) genenv;\n\
	\tenv->x = x;\n\
	\treturn poperator_if_init(env->x);\n\
}\n\
void* operator_if_init(){\n\
	\tstruct operator_if_cls* reserved = (struct operator_if_cls*)malloc(sizeof(*reserved));\n\
	\treserved->call = &operator_if_call;\n\
	\treturn (void*) reserved;\n\
}\n"

let llvmFuncDef (name : string) (args : string list) = 
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
    (builder, paramList)

(* function that performs function application *)
let applyFunc : string = 
    let (builder, f :: arg :: []) = 
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
    ignore(L.build_ret retval builder);

    "void* apply(void* f, void* arg){\n\
         \treturn (**((void* (**)(void*, void*)) f))(f, arg);\n\
     }\n"

(* struct corresponding to the initial state of the env *)
let primitiveEnv (typEnv : typeEnvironm) : string = 
    let capture = (M.fold (fun k _ acc -> k :: acc) 
                   typEnv
                   []) in
    let ccapture = sep ", *" capture in
    "struct primitiveEnv{ \n\
         \t void* (*call) (void*, void*);\n\
         \t void *" ^ ccapture ^ ";\n\
     };\n"

(* fixed includes and classes *)
let prelude (typEnv : typeEnvironm) : string = 
    "#include<stdio.h>\n\
     #include <stdlib.h>\n" ^
    applyFunc ^ 
    (primitiveEnv typEnv) ^ 
    ifstatement ^ 
    (primitiveBinaryFunc "add" "+") ^ 
    (primitiveBinaryFunc "sub" "-") ^
    (primitiveBinaryFunc "mlt" "*") ^
    (primitiveBinaryFunc "div" "/") ^ 
    (primitiveBinaryFunc "mod" "%") ^
    (primitiveBinaryFunc "and" "&") ^
    (primitiveBinaryFunc "or"  "|") ^
    (primitiveUnaryFunc  "not" "!") ^
    (primitiveBinaryFunc "eq"  "==")

let buildPrimitiveEnv : (string * typeEnvironm) = 
  let m = M.empty in
  let commonInttp = ArrowTyp(Concrete "Int", ArrowTyp(Concrete "Int", Concrete "Int")) in
  let commonBooltp = ArrowTyp(Concrete "Bool", ArrowTyp(Concrete "Bool", Concrete "Bool")) in
  let commonGenerictp = ArrowTyp(TypVar "a", ArrowTyp(TypVar "a", Concrete "Bool")) in
  let unaryBooltp = ArrowTyp(Concrete "Bool", Concrete "Bool") in
  let madd = M.add "operator_add" (Scheme([], commonInttp)) m in
  let msub = M.add "operator_sub" (Scheme([], commonInttp)) madd in
  let mmlt = M.add "operator_mlt" (Scheme([], commonInttp)) msub in
  let mdiv = M.add "operator_div" (Scheme([], commonInttp)) mmlt in
  let mmod = M.add "operator_mod" (Scheme([], commonInttp)) mdiv in
  let mand = M.add "operator_and" (Scheme([], commonBooltp)) mmod in
  let mor  = M.add "operator_or"  (Scheme([], commonBooltp)) mand in
  let mnot = M.add "operator_not" (Scheme([], unaryBooltp)) mor in
  let meq  = M.add "operator_eq"  (Scheme([], commonGenerictp)) mnot in
  let mif  = M.add "operator_if"  
                   (Scheme(["a"], ArrowTyp(Concrete "Bool",
                                         ArrowTyp(ArrowTyp(Concrete "Int", TypVar "a"), 
                                                  ArrowTyp(ArrowTyp(Concrete "Int", TypVar "a"), 
                                                           TypVar "a")))))
                   meq in

  (prelude mif, mif)

(* generates the C code for a function;     
   acts essentially as a lambda function written in C: each function has a
   unique corresponding class with its call operator and its capture *)
let cppfunction (name : string) (arg : string) 
                (body : string) (typEnv : typeEnvironm) : string = 
    let dummyScheme = Scheme([], (Concrete "Int")) in
    let capture = (M.fold (fun k _ acc -> k :: acc) 
                   (M.add arg dummyScheme typEnv) 
                   []) in
    let ccapture = sep ", *" capture in
    let vcapture = sep ", void* " (remove arg capture) in

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
                    "\t*((void**) reserved + " ^ (string_of_int !currIndex) ^ 
                    ") = " ^ v ^ ";\n")) capture) in


    let ftyp    = L.function_type voidptr (Array.of_list [voidptr; voidptr]) in 
    let funcptr = L.pointer_type ftyp in
    let structT = L.named_struct_type context ("struct." ^ mangleName name) in
    let strptrT = L.pointer_type structT in
    let _ = L.struct_set_body structT
                         (Array.append 
                             (Array.of_list [funcptr]) 
                             (Array.make (List.length capture) voidptr))
                         false in
    
    let (builder, params) = llvmFuncDef (mangleInit name) (remove arg capture) in
    
    let local = L.build_alloca strptrT "reserved" builder in

    "struct " ^ (mangleName name) ^ "{\n\
         \tvoid* (*call)(void*, void*);\n\
         \tvoid *" ^ ccapture ^ ";\n\
     };\n\
     void* " ^ (mangleCall name) ^ "(void* genenv, void* " ^ arg ^ "){\n\
         \tstruct " ^ (mangleName name) ^ 
                 " *env = (struct " ^ (mangleName name) ^ "*) genenv;\n\
         \t*((void**) env + " ^ (string_of_int (!argIndex)) ^ ") = " ^ arg ^ ";\n\
         \treturn " ^ body ^ ";\n\
     }\n\
     void* " ^ (mangleInit name) ^ "(void* " ^ vcapture ^ "){\n\
        \tstruct " ^ (mangleName name) ^ "* reserved = \
            (struct " ^ (mangleName name) ^ "*)malloc(sizeof(*reserved));\n\
        \t*(void* (**) (void*, void*)) reserved = &" ^ (mangleCall name) ^ ";\n" ^
        assigns ^ 
        "\treturn (void*) reserved;\n\
     }\n"

(* instantiate a class corresponding to a function *)
let cppfunctioninst (name : string) (arg : string) (typEnv : typeEnvironm) : string = 
    let capture = (M.fold (fun k _ acc -> k :: acc) typEnv []) in
    let currIndex = ref 0 in
    let assigns = 
            List.fold_left 
              (^) ""
              (List.map (fun v -> (
                  currIndex := !currIndex + 1;
                  if v = arg then ""
                  else
                    ", *((void**) env + " ^ (string_of_int !currIndex) ^ ")")) 
              capture) in

     (mangleInit name) ^ "(" ^ (String.sub assigns 2 (String.length assigns - 2))  ^ ")"

(* similar to the fix operator: enables recursion *)
let fix name arg typEnv codee = 
    let dummyScheme = Scheme([], (Concrete "Int")) in
    let capture = (M.fold (fun k _ acc -> k :: acc) 
                   (M.add arg dummyScheme typEnv) 
                   []) in
     let ccapture = sep ", *" capture in
     let vcapture = sep ", void *" (remove arg capture) in

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
                    "\t*((void**) env + " ^ (string_of_int !currIndex) ^ 
                    ") = " ^ v ^ ";\n")) capture) in

     "struct " ^ mangleEnv name ^ "{\n\
          \t void* (*call) (void*, void*);\n\
          \tvoid *" ^ ccapture ^ ";\n\
      };\n\
      void* " ^ mangleApp name ^ "(void* f, void *" ^ vcapture ^ "){\n\
          \tstruct " ^ mangleEnv name ^ "* env = malloc(sizeof(*env));\n"
          ^ assigns ^
         "\t*((void**) env + " ^ (string_of_int (!argIndex)) ^ ") = NULL;\n\
          \tvoid* arg = " ^ codee ^ ";\n\
          \t*(void**)(arg + " 
                 ^ string_of_int (1 + List.length capture) ^ 
                 " * sizeof(void*)) = arg;\n\
          \treturn apply(f, arg);\n\
      }\n"
