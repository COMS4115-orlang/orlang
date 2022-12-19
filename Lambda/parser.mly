%{ 
   open Ast 
   open List
   open Desugar
%}

%token MATCH WITH GUARD SEMICOLON ATT
%token LPAREN RPAREN 
%token LBRACKET RBRACKET COMMA
%token LAMBDA ARROW DARROW
%token PLUS MINUS TIMES DIV MOD FPLUS FMINUS FDIV FTIMES

%token LET REC EQUALS WHERE AND IN
%token IF THEN ELSE
%token EOF
%token VAL COLON DCOLON OTHERWISE
%token TRUE FALSE 
%token PRINTINT

%token BAND BOR BNOT DOUBLEEQUALS

%token <int> LITERAL
%token <float> FLITERAL
%token <string> VARIABLE
%token <string> TYPE TYPEVAR

%right ARROW DARROW
%left GUARD
%left ELSE
%left IN
%left COLON
%left DCOLON
%left DOUBLEEQUALS
%left BAND BOR
%left BNOT
%left PLUS MINUS FPLUS FMINUS
%left TIMES DIV MOD FTIMES FDIV

%start topLevel
%type <Ast.hExpr> topLevel
%type <Ast.binding> letBinding
%type <Ast.typ> monoType
%type <Ast.binding list> wheres 
%type <Ast.binding> binding
%type <Ast.hExpr> expr
%type <Ast.hExpr> call
%type <Ast.hExpr> arg

%%

topLevel:
| letBinding topLevel         { NoHint(Let($1, $2)) }
| typeAnn letBinding topLevel { let (v1, tp) = $1 in
                                let Binding(LVar(v2), _, _) = $2 in
                                if v1 = v2
                                then Hint(Let($2, $3), tp)
                                else raise(Failure("type annotation must be \
                                                    immediately followed by \
                                                    an accompanying definition"))
                              }
| letBinding                  { NoHint(Let($1, Hint(Var "main", Concrete "Int"))) }
| typeAnn letBinding          { let (v1, tp) = $1 in
                                let Binding(LVar(v2), _, _) = $2 in
                                if v1 = v2 
                                then Hint(Let($2, Hint(Var "main", Concrete "Int")), tp)
                                else raise(Failure("type annotation must be \
                                                    immediately followed by \
                                                    an accompanying definition"))
                              }

letBinding:
| LET REC binding             { let Binding(v, e, _) = $3 in Binding(v, e, true) }
| LET REC binding WHERE wheres{ let Binding(v, e, _) = $3 in 
                                let body = fold_right
                                  (fun (Binding(w, f, _)) acc -> 
                                      NoHint(Call(NoHint(Lambda(w, acc)), f)))  
                                  $5
                                  e in
                                Binding(v, body, true)
                              }
| LET binding                 { $2 }
| LET binding WHERE wheres    { let Binding(v, e, _) = $2 in 
                                let body = fold_right
                                  (fun (Binding(w, f, _)) acc -> 
                                      NoHint(Call(NoHint(Lambda(w, acc)), f)))  
                                  $4
                                  e in
                                Binding(v, body, false)
                              }

wheres:
| binding AND wheres          { $1 :: $3 }
| binding                     { [$1] }

binding:
| VARIABLE EQUALS expr        { Binding(LVar($1), $3, false) }
| VARIABLE binding            { let Binding(v, e, _) = $2
                                in Binding(LVar($1), NoHint(Lambda(v, e)), false) }
| LPAREN multVars RPAREN EQUALS expr   { MBinding($2, $5) }
| LPAREN consVars RPAREN EQUALS expr   { CBinding($2, $5) }


typeAnn:
| VAL VARIABLE COLON monoType { ($2, $4) }

monoType:
| TYPE                        { Concrete($1) }
| TYPEVAR                     { TypVar($1) }
| LPAREN monoType RPAREN      { $2 }
| monoType ARROW monoType     { ArrowTyp($1, $3) }



expr:
| call                        { $1 }
| expr COLON monoType         { match $1 with
                                | NoHint(e) -> Hint(e, $3)
                                | Hint(e, t) -> if t = $3
                                                then Hint(e, $3)
                                                else raise(Failure(
                                                     "multiple distinct type annotations \
                                                      referencing the same construct"))
                              }
| LAMBDA lambda               { $2 }
| LET binding IN expr         { NoHint(Let($2, $4)) }
| expr PLUS  expr            { NoHint(Binop(ADD, $1, $3)) }
| expr MINUS expr            { NoHint(Binop(SUB, $1, $3)) }
| expr TIMES expr            { NoHint(Binop(MLT, $1, $3)) }
| expr DIV   expr            { NoHint(Binop(DIV, $1, $3)) }
| expr MOD   expr            { NoHint(Binop(MOD, $1, $3)) }
| expr FPLUS  expr           { NoHint(Binop(FADD, $1, $3)) }
| expr FMINUS expr           { NoHint(Binop(FSUB, $1, $3)) }
| expr FTIMES expr           { NoHint(Binop(FMLT, $1, $3)) }
| expr FDIV   expr           { NoHint(Binop(FDIV, $1, $3)) }
| expr BAND  expr            { NoHint(Binop(AND, $1, $3)) }
| expr BOR   expr            { NoHint(Binop(OR, $1, $3)) }
| expr COLON expr            { NoHint(LCons($1, $3)) }
| expr DOUBLEEQUALS   expr   { NoHint(Binop(EQ, $1, $3)) }
| BNOT  expr                 { NoHint(Unop(NOT, $2)) }
| IF expr THEN expr ELSE expr { NoHint(If($2, $4, $6)) }
| MATCH expr WITH patternMatrix SEMICOLON { patternsToIfElse(PatternMatch($2, $4)) }
| LBRACKET lst RBRACKET       { NoHint(ListLit($2)) }
| ATT expr ATT            { NoHint(LLen($2)) }
| PRINTINT LPAREN expr LPAREN { NoHint(PrintInt($3)) }

multVars:
| VARIABLE COMMA multVars { (LVar($1))::($3) }
| VARIABLE                { [LVar($1)] }

consVars:
| VARIABLE DCOLON consVars { (LVar($1))::($3) }
| VARIABLE                 { [LVar($1)] }

lst:
|                             { [] }
| expr                        { [$1] }
| expr COMMA lst              { ($1)::($3) }

exprList:
| expr                { [$1] }
| expr COMMA exprList { ($1)::($3) }

patternMatrix: 
| GUARD expr DARROW expr               { [PatternRow(Pattern($2), $4)] }
| GUARD OTHERWISE DARROW expr         { [PatternRow(PatDefault, $4)] }
| GUARD expr DARROW expr patternMatrix { PatternRow(Pattern($2), $4)::($5) }

lambda:
| VARIABLE ARROW expr         { NoHint(Lambda(LVar($1), $3)) }
| VARIABLE lambda             { NoHint(Lambda(LVar($1), $2)) }

call:
| arg                         { $1 }
| call arg                    { NoHint(Call($1, $2)) }

arg:
| LITERAL                     { NoHint(IntLit($1)) }
| FLITERAL                    { NoHint(FloatLit($1)) }
| TRUE                        { NoHint(BoolLit(1)) }
| FALSE                       { NoHint(BoolLit(0)) }
| VARIABLE                    { NoHint(Var($1)) }
| LPAREN expr RPAREN          { $2 }
