# Orlang

Update: 12/20/2022 (Final Project Submission)

## 1. File Structure
- `ast.mli`: Orlang's AST and SAST definitions
- `codegen.ml`: Orlang's codegen subroutines for generating LLVM IR from Orlang
- `desugar.ml`: Orlang's pattern matching subroutines
- `instantiation.ml`: initialization/generalization methods for Hindly Milner type inference
- `orlang.ml`: entry point to compiler
- `parser.mly`: Orlang's Parser
- `scanner.mll`: Orlang's Scanner
- `semant.ml`: Orlang's semantic checking. Currently checks for type errors (via Algorithm W) and unused variables
- `unification.ml`: Unification module used in Algorithm W
- `Makefile`: For your convenience when running tests
- `tests/`: Testcases for Orlang and Prelude

## 2. Running Orlang on tests
Preparation 
```
$ sudo apt-get install ocaml-findlib
$ opam install llvm
```
First, build orlang via
```
$ make
```
in the root directory. Then, run
```
$ make all_tests
```
To compile individual files
```
$ ./orlang.native <input_file> <output_file>
```

