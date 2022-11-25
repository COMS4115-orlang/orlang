type operator = Add | Sub | Mlt | Div | Mod

type lvalue =
  | LVar of string

type typ = 
    Concrete of string
  | TypVar of string
  | ArrowTyp of typ * typ

type binop = ADD | SUB | MLT | DIV | MOD | AND | OR | EQ
type unop = NOT

type expr =
    IntLit of int
  | BoolLit of int
  | Binop of binop * hExpr * hExpr
  | Unop of unop * hExpr
  | Var of string
  | Call of hExpr * hExpr
  | Lambda of lvalue * hExpr
  | If of hExpr * hExpr * hExpr
  | Let of binding * hExpr
  | PatternMatch of hExpr * (patternRow list) 
and hExpr = 
    NoHint of expr
  | Hint of expr * typ
and binding = 
    Binding of lvalue * hExpr * bool
and patternRow = 
  | PatternRow of pattern * hExpr
and pattern = 
    PatWildCard
  | PatId of string
  | PatLit of int
  | PatCon of string * (hExpr list)


type scheme =
  | Scheme of string list * typ

(* semantically checked expression; everything in orlang is an exprssion *)
type sExpr = typ * sx 
and sx =
    SIntLit of int
  | SBoolLit of int
  | SBinop of binop * sExpr * sExpr
  | SUnop of unop * sExpr
  | SIf of sExpr * sExpr * sExpr
  | SVar of string
  | SCall of sExpr * sExpr
  | SLambda of lvalue * sExpr
  | SLet of sbinding * sExpr
and sbinding = 
    SBinding of lvalue * sExpr * bool

