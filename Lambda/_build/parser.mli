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
  | LAMBDA
  | ARROW
  | PLUS
  | MINUS
  | TIMES
  | DIV
  | MOD
  | LET
  | REC
  | EQUALS
  | WHERE
  | AND
  | IN
  | IF
  | THEN
  | ELSE
  | PIF
  | PTHEN
  | PELSE
  | EOF
  | VAL
  | COLON
  | TRUE
  | FALSE
  | BAND
  | BOR
  | BNOT
  | DOUBLEEQUALS
  | LITERAL of (int)
  | VARIABLE of (string)
  | TYPE of (string)
  | TYPEVAR of (string)

val topLevel :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Ast.hExpr
