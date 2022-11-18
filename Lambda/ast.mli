type operator = Add | Sub | Mlt | Div | Mod

type lvalue =
  | LVar of string

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
and typ = 
    Concrete of string
  | TypVar of string
  | ArrowTyp of typ * typ

type scheme =
  | Scheme of string list * typ

