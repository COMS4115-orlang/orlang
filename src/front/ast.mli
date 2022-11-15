type operator = Add | Sub | Mlt | Div | Mod

type idenfitier = 
  | Identifier of string

type pattern = 
    PatWildCard
  | PatId of identifier
  | PatLit of literal
  | PatTup of pattern list
  | PatApp of pattern list

type literal = 
    IntLit of int
  | FloatLit of float
  | BoolLit of bool
  | CharLit of char
  | StringLit of string

type typ =
    TCon of Identifier
  | TApp of typ * typ
  | TTuple of typ list
  | TArrow of typ * typ

type typAnn = typ

type typFn =
    TypReturn of typAnn
  | TypProper of typAnn
  | TypNone

type typCon =
  | TypCon of identifer * (typ list)

type definition = 
    DefFn of identifier * pattern * typFn * expr
  | DefPat of pattern * expr

type expr = 
    Id of identifier
  | Lit of literal
  | IfElse of expr * expr * expr
  | Let of definition * expr
  | Lambda of pattern * expr  
  | Apply of expr * expr
  | Assign of expr * expr
  | Match of expr * ((pattern * expr) list)

type scheme =
  | Scheme of string list * typ

