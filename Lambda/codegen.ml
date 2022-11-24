open Ast
open Unification
open Instantiation
open Cpp
module M = Map.Make(String)
module S = Set.Make(String)

let classes = ref ""

let find x ys = 
    let rec helper x index = function
    |  []     -> raise(Failure("impossible"))
    | y :: ys -> if x = y then index
                          else helper x (index + 1) ys
    in helper x 0 ys

let rec check (sexpr : sExpr) (typEnv : typeEnvironm) : codegenResult =
  let (_, expr) = sexpr in
  match expr with
  | SVar (s)             -> 
          let var = "_" ^ (nextEntry lastTemp) in
          let ordered = (M.fold (fun k _ acc -> k :: acc) typEnv []) in
          let index = find s ordered in
              { code  = "\tvoid* " ^ var ^ 
                        " = (*((void**) env + 1 + " ^ string_of_int index ^ "));\n";
                var   = var;
              }
(*---------------------------------------------------------------------------*)  
  | SIntLit (i)          ->
          let var = "_" ^ (nextEntry lastTemp) in
          { code  = "\tvoid* " ^ var ^ " = ((void*) " ^ string_of_int i ^ ");\n";
            var   = var;
          }
(*---------------------------------------------------------------------------*)  
  | SBoolLit (b)         ->
          let var = "_" ^ (nextEntry lastTemp) in
          { code  = "\tvoid* " ^ var ^ " = ((void*) " ^ string_of_int b ^ ");\n";
            var   = var;
          }
(*---------------------------------------------------------------------------*)  
  | SLambda (LVar(v), e) -> 
          let typEnvNew = M.add v (Scheme([], Concrete "Int")) typEnv in
          let { code  = code; 
                var   = evar; } = check e typEnvNew in

          let name = nextEntry lastClass in
          let var = "_" ^ (nextEntry lastTemp) in
          (
              (* generate the code for the class/call/constructor of this lambda *)
              classes := !classes ^ 
                         cppfunction name v (code, evar) typEnv;
              { code  = cppfunctioninst var name v typEnv;
                var   = var;
              }
          )
(*---------------------------------------------------------------------------*)  
  | SCall (f, arg)       -> 
          let { code  = codef; 
                var   = fvar; } = check f typEnv in 
          let { code  = codearg;
                var   = argvar; } = check arg typEnv in
          
          let var = "_" ^ (nextEntry lastTemp) in
          { code  = codef ^ codearg ^ 
                    "\tvoid* " ^ var ^ " = apply(" ^ fvar ^ ", " ^ argvar ^ ");\n";
            var   = var;
          }
(*---------------------------------------------------------------------------*)  
  | SLet (SBinding(LVar(v), e, false), f) ->
          let { code  = codee; 
                var   = evar; } = check e typEnv in
          let typEnvNew = M.add v (Scheme([], Concrete "Int")) typEnv in
          let { code  = codef; 
                var   = fvar; } = check f typEnvNew in
          let name = nextEntry lastClass in

          let var = "_" ^ (nextEntry lastTemp) in
          let tmp = "_" ^ (nextEntry lastTemp) in
          (
              (* C code is equivalent to lambda and call *)
              classes := !classes ^ 
                         cppfunction name v (codef, fvar) typEnv;
              { code  = codee ^ 
                        (cppfunctioninst tmp name v typEnv) ^ 
                        "\tvoid* " ^ var ^ 
                        " = apply(" ^ tmp ^ ", " ^ evar ^ ");\n";
                var   = var;
              }
          )
(*---------------------------------------------------------------------------*)  
  | SLet (SBinding(LVar(v), e, _), f)  ->

        let typEnvNew = M.add v (Scheme ([], Concrete "Int")) typEnv in
        let { code  = codee; 
              var   = evar; } = check e typEnvNew in
        
        let { code  = codef; 
              var   = fvar; } = check f typEnvNew in

        
        (* special code generation for recursive let-bindings *)
        let name = nextEntry lastClass in
        let capture = (remove v 
                      (M.fold (fun k _ acc -> k :: acc) typEnv [])) in
        let acapture = sep ", env->" capture in
        let var = "_" ^ (nextEntry lastTemp) in
        let tmp = "_" ^ (nextEntry lastTemp) in
        let func = cppfunctioninst tmp name v typEnv in
        (
            (* C code is equivalent to lambda and call *)
            classes := !classes ^ 
                       cppfunction name v (codef, fvar) typEnv ^
                       fix name v typEnv (codee, evar);
            { code  = func ^ 
                      "\tvoid* " ^ var ^ " = " ^ 
                           (mangleApp name) ^ "(" ^ tmp ^ ", env->" ^ acapture ^ ");\n";
              var   = var;
            }
        )

