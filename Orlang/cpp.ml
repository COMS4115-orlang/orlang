open Unification
module M = Map.Make(String)

(* All but the last element of a list *)
let rec init : 'a list -> 'a list = function
  | [] -> []
  | _ :: [] -> []
  | x :: xs -> x :: (init xs)

(* last element of a list *)
let rec lst : 'a list -> 'a = function
  | [] -> raise (Failure ("invalid call to last"))
  | x :: [] -> x
  | _ :: xs -> lst xs

(* Helpers *)
let checkVar (s : string) : string = 
    if s = "main" then "Main" else s

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

(* function that performs function application *)
let applyFunc : string = 
    "void* apply(void* f, void* arg){\n\
         \treturn (**((void* (**)(void*, void*)) f))(f, arg);\n\
     }\n"

(* struct corresponding to the initial state of the env *)
let primitiveEnv : string = 
    "struct primitiveEnv{ \n\
         \t void *operator_add, *operator_sub, \
                 *operator_mlt, *operator_div, \
                 *operator_mod, *operator_and, \
                 *operator_or , *operator_not, \
                 *operator_if , *operator_eq;\n\
     };\n"

(* fixed includes and classes *)
let prelude : string = 
    "#include<stdio.h>\n\
     #include <stdlib.h>\n" ^
    applyFunc ^ 
    primitiveEnv ^ 
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

(* generates the C code for a function;     
   acts essentially as a lambda function written in C: each function has a
   unique corresponding class with its call operator and its capture *)
let cppfunction (name : string) (arg : string) 
                (body : string) (typEnv : typeEnvironm) : string = 
    let capture = (remove "main" 
                  (remove (checkVar arg) 
                  (M.fold (fun k _ acc -> k :: acc) typEnv []))) in
    let ccapture = sep ", *" capture in
    let vcapture = sep ", void* " capture in
    let assigns = 
            List.fold_left 
              (^) ""
              (List.map (fun v -> "\treserved->" ^ v ^ " = " ^ v ^ ";\n") capture) in

    "struct " ^ (mangleName name) ^ "{\n\
         \tvoid* (*call)(void*, void*);\n\
         \tvoid *" ^ ccapture ^ ", *" ^ (checkVar arg) ^ ";\n\
     };\n\
     void* " ^ (mangleCall name) ^ "(void* genenv, void* " ^ (checkVar arg) ^ "){\n\
         \tstruct " ^ (mangleName name) ^ 
                 " *env = (struct " ^ (mangleName name) ^ "*) genenv;\n\
         \tenv->" ^ (checkVar arg) ^ " = " ^ (checkVar arg) ^ ";\n\
         \treturn " ^ body ^ ";\n\
     }\n\
     void* " ^ (mangleInit name) ^ "(void* " ^ vcapture ^ "){\n\
        \tstruct " ^ (mangleName name) ^ "* reserved = \
            (struct " ^ (mangleName name) ^ "*)malloc(sizeof(*reserved));\n\
        \treserved->call = &" ^ (mangleCall name) ^ ";\n" ^
        assigns ^ 
        "\treturn (void*) reserved;\n\
     }\n"

(* instantiate a class corresponding to a function *)
let cppfunctioninst (name : string) (arg : string) (typEnv : typeEnvironm) : string = 
     let capture = (remove "main" 
                   (remove (checkVar arg) 
                   (M.fold (fun k _ acc -> k :: acc) typEnv []))) in
     let conscapture = sep ", env->" capture in
     (mangleInit name) ^ "(env->" ^ conscapture  ^ ")"

(* similar to the fix operator: enables recursion *)
let fix name arg typEnv codee = 
     let capture = (remove "main" 
                   (remove (checkVar arg) 
                   (M.fold (fun k _ acc -> k :: acc) typEnv []))) in
     let ccapture = sep ", *" capture in
     let vcapture = sep ", void *" capture in

     let assigns = 
            List.fold_left 
              (^) ""
              (List.map (fun v -> "\tenv->" ^ v ^ " = " ^ v ^ ";\n") capture) in

     "struct " ^ mangleEnv name ^ "{\n\
          \tvoid *" ^ ccapture ^ ", *" ^ arg ^";\n\
      };\n\
      void* " ^ mangleApp name ^ "(void* f, void *" ^ vcapture ^ "){\n\
          \tstruct " ^ mangleEnv name ^ "* env = malloc(sizeof(*env));\n"
          ^ assigns ^
         "\tenv->" ^ arg ^ " = NULL;\n\
          \tvoid* arg = " ^ codee ^ ";\n\
          \t*(void**)(arg + " 
                 ^ string_of_int (1 + List.length capture) ^ 
                 " * sizeof(void*)) = arg;\n\
          \treturn apply(f, arg);\n\
      }\n"
