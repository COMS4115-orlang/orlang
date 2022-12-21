{ open Parser 
  open Char }

let digit = ['0'-'9']
let sign = ('+'|'-')?
let expon = ('e'|'E') sign digit+
let dec = '.'

rule tokenize = parse
| [' ' '\t' '\r' '\n'] { tokenize lexbuf }
| "(*"  { comment 1 lexbuf }
| '+'   { PLUS }
| "+."  { FPLUS }
| '-'   { MINUS }
| "-."  { FMINUS }
| '*'   { TIMES }
| "*."  { FTIMES }
| '/'   { DIV }
| "/."  { FDIV }
| '%'   { MOD }
| "%."  { FMOD }
| "()"  { UNIT }
| '('   { LPAREN }
| ')'   { RPAREN }
| '['   { LBRACKET }
| ']'   { RBRACKET }
| ','   { COMMA }
| "=="  { DOUBLEEQUALS }
| '<'   { LT }
| "<="  { LTE }
| '>'   { GT }
| ">="  { GTE }
| '='   { EQUALS }
| "&&"  { BAND }
| "||"  { BOR }
| "!"   { BNOT }
| '\\'  { LAMBDA }
| "->"  { ARROW }
| "=>"  { DARROW }
| ":"   { COLON }
| "::"  { DCOLON }
| "val"   { VAL }
| "let"   { LET }
| "rec"   { REC }
| "in"    { IN }
| "where" { WHERE }
| "and"   { AND }
| "if"    { IF }
| "then"  { THEN }
| "else"  { ELSE }
| "match" { MATCH}
| "with"  { WITH }
| "print_internal"  { PRINT }
| "ord_internal"    { ORD }
| "chr_internal"    { CHR }
| "fptosi_internal" { FPTOSI }
| "sitofp_internal" { SITOFP }
| "|"     { GUARD }
| "|."    { GUARDDOT }
| ".|"    { DOTGUARD }
| ";"     { SEMICOLON }
| "otherwise"   { OTHERWISE }
| sign? digit+ as lit                      { LITERAL(int_of_string lit) }
| sign? (digit* dec digit+ expon?) as lit  { FLITERAL(float_of_string lit) }
| sign? (digit* dec? digit+ expon) as lit  { FLITERAL(float_of_string lit) }
| sign? (digit+ dec digit* expon?) as lit  { FLITERAL(float_of_string lit) }
| sign? (digit+ dec? digit* expon) as lit  { FLITERAL(float_of_string lit) }
| "'\\n'" { CLITERAL (code '\n') }
| "'\\r'" { CLITERAL (code '\r') }
| "'\\t'" { CLITERAL (code '\t') }
| "'\\b'" { CLITERAL (code '\b') }
| "'\\''" { CLITERAL (code '\'') }
| "'" (_ as character) "'" { CLITERAL(code character) }
| "true"  { TRUE }
| "false" { FALSE }
| ['a'-'z'] ['a'-'z' 'A'-'Z' '0'-'9' '_' ]* as id { VARIABLE(id) }
| "List"  { LIST }
| ['A'-'Z'] ['a'-'z' 'A'-'Z' '0'-'9']* as id      { TYPE(id) }
| '\''['a'-'z'] ['a'-'z' 'A'-'Z' '0'-'9']* as id  { TYPEVAR(id) }
| eof     { EOF }

and comment level = parse
| "*)" { if level = 1 then tokenize lexbuf 
         else comment (level - 1) lexbuf }
| "(*" { comment (level + 1) lexbuf }
| _    { comment level lexbuf }
