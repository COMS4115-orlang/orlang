open Ast

let patternsToIfElse (pats : patternMatch) =
    let PatternMatch(ex, pmat) = pats in
    let rec desugarPatRows (patmat : patternRow list) =
        match patmat with
        | (PatternRow(Pattern(p), a))::((_::xs) as nxt) -> 
                let eqCond = NoHint(Binop(EQ, ex, p)) in
                NoHint(If(eqCond, a, (desugarPatRows nxt))) 
        | [PatternRow(PatDefault, a)]    -> a
        | [PatternRow(_, a)]             ->
                raise(Failure("Missing a default case for pattern matching"))
        | _                              -> 
                raise(Failure("Desugaring invalid pattern matching"))
    in desugarPatRows pmat 
