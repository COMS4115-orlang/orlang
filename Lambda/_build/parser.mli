type token =
  | MATCH
  | WITH
  | GUARD
  | SEMICOLON
  | LPAREN
  | RPAREN
  | LBRACKET
  | RBRACKET
  | COMMA
  | GUARDDOT
  | DOTGUARD
  | LAMBDA
  | ARROW
  | DARROW
  | PLUS
  | MINUS
  | TIMES
  | DIV
  | MOD
  | FPLUS
  | FMINUS
  | FDIV
  | FTIMES
  | FMOD
  | LET
  | REC
  | EQUALS
  | WHERE
  | AND
  | IN
  | IF
  | THEN
  | ELSE
  | EOF
  | VAL
  | COLON
  | DCOLON
  | OTHERWISE
  | TRUE
  | FALSE
  | PRINT
  | ORD
  | CHR
  | FPTOSI
  | SITOFP
  | BAND
  | BOR
  | BNOT
  | DOUBLEEQUALS
  | LT
  | LTE
  | GT
  | GTE
  | UNIT
  | LIST
  | LITERAL of (int)
  | CLITERAL of (int)
  | FLITERAL of (float)
  | VARIABLE of (string)
  | TYPE of (string)
  | TYPEVAR of (string)

val topLevel :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Ast.hExpr
