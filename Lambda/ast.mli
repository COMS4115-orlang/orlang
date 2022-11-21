type operator = Add | Sub | Mlt | Div | Mod

type lvalue =
  | LVar of string

type typ = 
    Concrete of string
  | TypVar of string
  | ArrowTyp of typ * typ

type expr =
    IntLit of int
  | BoolLit of int
  | Var of string
  | Call of hExpr * hExpr
  | Lambda of lvalue * hExpr
  | If of hExpr * hExpr * hExpr
  | Let of binding * hExpr
and hExpr = 
    NoHint of expr
  | Hint of expr * typ
and binding = 
    Binding of lvalue * hExpr * bool

type scheme =
  | Scheme of string list * typ

(* semantically checked expression; everything in orlang is an exprssion *)
type sExpr = typ * sx 
and sx =
    SIntLit of int
  | SBoolLit of int
  | SVar of string
  | SCall of sExpr * sExpr
  | SLambda of lvalue * sExpr
  | SIf of sExpr * sExpr * sExpr
  | SLet of sbinding * sExpr
and sbinding = 
    SBinding of lvalue * sExpr * bool

