{ open Parser }

rule tokenize = parse
| [' ' '\t' '\r' '\n'] { tokenize lexbuf }
| "(*"  { comment 1 lexbuf }
| '+'   { PLUS }
| '-'   { MINUS }
| '*'   { TIMES }
| '/'   { DIV }
| '%'   { MOD }
| '('   { LPAREN }
| ')'   { RPAREN }
| '['   { LBRACKET }
| ']'   { RBRACKET }
| ','   { COMMA }
| "=="  { DOUBLEEQUALS }
| '='   { EQUALS }
| "&&"  { BAND }
| "||"  { BOR }
| "!"   { BNOT }
| '\\'  { LAMBDA }
| "->"  { ARROW }
| ":"   { COLON }
| "val" { VAL }
| "let" { LET }
| "rec" { REC }
| "in"  { IN }
| "where" { WHERE }
| "and" { AND }
| "if"  { IF }
| "then" { THEN }
| "else" { ELSE }
| "match" { MATCH}
| "with" { WITH }
| "|"   { GUARD }
| ";"   { SEMICOLON }
| ['0'-'9']+ as lit { LITERAL(int_of_string lit) }
| "true" { TRUE }
| "false" { FALSE } 
| ['a'-'z'] ['a'-'z' 'A'-'Z' '0'-'9']* as id { VARIABLE(id) }
| ['A'-'Z'] ['a'-'z' 'A'-'Z' '0'-'9']* as id { TYPE(id) }
| '\''['a'-'z'] ['a'-'z' 'A'-'Z' '0'-'9']* as id { TYPEVAR(id) }
| eof { EOF }

and comment level = parse
| "*)" { if level = 1 then tokenize lexbuf 
         else comment (level - 1) lexbuf }
| "(*" { comment (level + 1) lexbuf }
| _    { comment level lexbuf }
