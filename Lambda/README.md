# Orlang

Update: 11/21/2022 (Mid-term project Hello-World Submission)

## 1. File Structure
- `ast.mli`: Orlang's AST and SAST definitions
- `scanner.mll`: Orlang's Scanner
- `parser.mly`: Orlang's Parser
- `semant.ml`: Orlang's semantic checking. Currently checks for type errors (via Algorithm W) and unused variables
- `unification.ml`: Unification module used in Algorithm W
- `instantiation.ml`: initialization/generalization methods for Hindly Milner type inference
- `cgen.ml`: Orlang's (very rough) codegen subroutines for generating C code from Orlang.
- `Makefile`: For your convenience when running tests
- `tests/`: Testcases for Orlang

## 2. Running Orlang on tests
First, build orlang via
```
$ ocamlbuild orlang.native > orlang

# alternatively...
$ make build
```
in the root directory. Then, run
```
$ orlang.native < tests/test{n}.orl > tests/test{n}.out.c

# alternatively... (replace 1 below with any test case number)
$ make n=1 test
```
where `n` is the testcase number.

You can either `cat tests/test{n}.out.c` or compile it with `gcc` and then run the executable

## 3. Features Implemented
Below are some noteworthy features we have implemented so far:
- **Lambdas**: We support single/multi-variable lambda expressions (anonymous functions):
  ```
  let five =
    let f = (\x y -> 1 * (x - 2) * y) in 
    let g x y = x * y in
    let x = 3 in
    let y = 4 in
    f (g x 2 - 3) ((\z -> z + 1) y)
  ```

- **Type System**: We have implemented a variant of the Hindley-Milner type system via Algorithm W. We can infer
  types and check for type errors at compilation time. To support this, we have implemented a `unification` module. 
  In particular, our implementation obeys the limitation of HM that polymorphism can only be introduced via `let` 
  bindings (i.e. let polymorphism), with every other construct - lambdas, most importantly - being monomorphic. Additionally, 
  a name introduced recursively via let polymorphism must be used monomorphically within its definition, with polymorphism allowed only
  afterwards.

- **Type Annotations**: We support type annotations, which are incorporated into our HM type system. Our type annotation
  mechansim is slightly different from OCaml/Haskell in the following ways: (a) we allow annotation of top-level let-bindings 
  via the `val` keywords and annotation of expressions via the `:` operator (whose precedence is defined in our parser) - see example below; in
  particular, Orlang does not allow the inline type annotation of names introduced via `let` (e.g. `let x : int = ...` is not allowed) 
  (b) all type annotations are monomorphic, and are maximally generalized in the context of let-bindings; this means that, in the context of
  let-bindings, type annotations assume maximal polymorphism, whereas, in any other case, they remain monomorphic (c) any type annotation is
  valid as long as it can be unified with its inferred type, even if it is more general than the most general unifier.

  ```
  val add : Int -> Int -> Int
  let add x y = (x : Int) + (y : Int)

  val subtract : Int -> Int -> Int
  let subtract x y = x - y : Int
  ```

- **Recursion**: We support the definition of  recursive functions via `let rec`. For the sake of clarity and correcness, we explicitly disallow
  variables of a non-arrow type from being defined recursively.
  ```
  val fac : Int -> Int
  let rec fac n = 
    if n == 0 then 0
    else if n == 1 then 1
    else (fac (n - 1)) + (fac (n - 2))

  (* non-recursive functions can't be defined with the `rec` keyword; the following fails *)
  let rec x = 1
  ```

- **Pattern Matching front-end**: We have implemented pattern matching at the scanning/parsing level. The following describes a
  use case:
  ```
  let example (x : Int) =
    match x with
    | 0 = 1
    | _ = 0;
  ```
  Not that, unlike `OCaml`, all branches must start with a guard (vertical bar `|`).
 
- **Very rough C codegen**: We can generate pure `C` code from Orlang. This is just a placeholder and will soon be replaced. We assume
this step will help us transition to LLVM IR as we begin implementing the backend. The most important decisions so far are that (a)
all variables/functions in Orlang will be represented as untyped pointers (void*), which are casted depending on the context they are used in;
the Type Checking mechanism guarantees that such casts are valid (b) implementation of lambda expressions is similar to how they are handled
in C++ (each lambda is an instance of a unique class, which contains its capture and a call operator - in pure C, a function pointer). Our C
translation was designed to support Currying, hence the increase in generated code size.


## 4. Features in progress or to be implemented
- **Desugaring Pattern Matching**: While we have defined how pattern matching
should behave at the scanner/parser level, we are still working on its desugaring. We have begun writing
a very primitive desugaring algorithm (e.g. nested `if-then-else`), we may consider more efficient
compilation methods (e.g. decision trees) if time permits. 

- **Semantically Checking Pattern Matching**: We are also implementing anomaly detection (nonexhaustion and useless clause).

- **Algebraic Data Types**: We hope to support algebraic data types (union and product types) 

- **List and Tuples**: We need proper support for list and tuples

- **Parallelism**: We are currently doing discovery work on how to support parallelism (stateless, to being with)
in the LLVM setting.

- **Message Passing Concurrency**: We are also doing discovery on how to support message passing concurrency (lock-free).
We envision building a runtime library implementing bidirectional message queues.

## 5. Major changes to LRM
We have made no significant changes to our LRM. Included in the submission is our updated LRM with minor modifications.

## 6. Breakdown of Contributions
Everyone participated in formally defining our language (and thus our AST, scanner, parser); high-level discussions to solidfy our language featuers; and our approaches to implementing them. 

- Andrei: Implemented bulk of the parser. Implemented our unification module and Algorithm W for our Hindley Milner Type System; Implemented support for type annotations; Implemented the `C` codegen to translate Orlang to `C`. Writing testcases for Orlang. 

- Christopher: Wrote scanner and implemented semantic checking based on Andrei's type system work. Wrote initial unification and union-find module with Eumin which was deprecated (we decided to use Andrei's implemention of substituion-based unification and HM type system). Implenting support for pattern matching, as well as pattern matching anomaly detection. Did refactoring to integrate teammates' work.

- Eumin: Writing testcases for Orlang. Wrote initial unification and union-find module with Chris which was deprecated (we decided to use Andrei's implemention of substituion-based unification and HM type system). Discovery work on ADTs and List & Tuple desugaring. Wrote testcases for orlang. 

- Scott and Alan: Working on a draft implementation of bidrectional message queues (via unix domain sockets) as a runtime C library. Discovery work on incorporating thread-based parallelism in the LLVM setting and the actor-model for message passing concurrency. Wrote testcases for orlang. 

## 7. Test Cases
We give a high-level description of the test-cases we wrote.
- `test1.orl`: Monomorphism; non-recursive let bindings; lambdas; multi-variable lambdas; nested comments; function application; currying; `where` clause desugaring

- `test2.orl`: Monomorphism; non-recursive let bindings

- `test3.orl`: booleans, and, or, not, if statement 

- `test4.orl`: Let polymorphism; recursive let bindings used polymorphically outside of their definition and monomorphically inside of their definition; redundant recursion

- `test5.orl`: Type annotations

- `test{6, 7, 11, 12, 13, 14, 15, 17}.orl`: Unification errors (e.g. type errors)

- `test8.orl`: Semantic errors (undefined variable)

- `test9.orl`: Error (infinite functions)

- `test10.orl`: Example of pattern matching

- `test16.orl`: Illegal recursion
