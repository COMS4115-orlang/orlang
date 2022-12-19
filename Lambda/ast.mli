type operator = Add | Sub | Mlt | Div | Mod

type lvalue =
  | LVar of string

type typ = 
    Concrete of string
  | Unit
  | TypVar of string
  | ArrowTyp of typ * typ
  | ListTyp of typ

type binop = ADD | SUB | MLT | DIV | MOD 
           | AND | OR 
           | EQ | LT | LTE | GT | GTE 
           | FADD | FSUB | FMLT | FDIV
           | LCAT

type unop = NOT

type expr =
    IntLit of int
  | CharLit of int
  | BoolLit of int
  | FloatLit of float
  | UnitLit
  | ListLit of hExpr list
  | Binop of binop * hExpr * hExpr
  | LCons of hExpr * hExpr
  | LLen of hExpr
  | Print of hExpr
  | Unop of unop * hExpr
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
  | MBinding of (lvalue list) * hExpr
  | CBinding of (lvalue list) * hExpr

type patternMatch = 
    PatternMatch of hExpr * (patternRow list)
and patternRow = 
    PatternRow of pattern * hExpr
and pattern = 
    Pattern of hExpr
  | PatDefault

type scheme =
  | Scheme of string list * typ

(* semantically checked expression; everything in orlang is an expression *)
type sExpr = typ * sx 
and sx =
    SIntLit of int
  | SCharLit of int
  | SBoolLit of int
  | SUnitLit
  | SFloatLit of float
  | SListLit of sExpr list
  | SBinop of binop * sExpr * sExpr
  | SUnop of unop * sExpr
  | SLCons of sExpr * sExpr
  | SLLen of sExpr
  | SPrint of sExpr
  | SIf of sExpr * sExpr * sExpr
  | SVar of string
  | SCall of sExpr * sExpr
  | SLambda of lvalue * sExpr
  | SLet of sbinding * sExpr
and sbinding = 
    SBinding of lvalue * sExpr * bool
  | SMBinding of (lvalue list) * sExpr
  | SCBinding of (lvalue list) * sExpr
