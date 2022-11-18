all : calc.out

##############################
#
# HW 2: Question 1
#
# Compilation: 
# Option 1: Simply type "make" to compile the calculator (recommended, auto-test included)
# Option 2: "ocamlbuild calc.native" will also build the calculator

# For testing, you can run the binary executable and test it with
# standard input via terminal.
# Or use calc.tb (testbench file): you can modify the file directly
# with the exprssion you want to test before make. After compiling
# your executable successfully, the output of test case will be 
# generate automatically in a file named calc.out


calc : unification.cmo instantiation.cmo cpp.cmo parser.cmo scanner.cmo calc.cmo
	ocamlc -w A -o calc $^

%.cmo : %.ml
	ocamlc -w A -c $<

%.cmi : %.mli
	ocamlc -w A -c $<

scanner.ml : scanner.mll
	ocamllex $^

parser.ml parser.mli : parser.mly
	ocamlyacc -v $^

calc.out : calc tests/test1.tb tests/test2.tb tests/test3.tb tests/test4.tb tests/test5.tb
	./calc < tests/test1.tb > tests/test1.c
	./calc < tests/test2.tb > tests/test2.c
	./calc < tests/test3.tb > tests/test3.c
	./calc < tests/test4.tb > tests/test4.c
	./calc < tests/test5.tb > tests/test5.c
	./calc < tests/test6.tb > tests/test6.c
	./calc < tests/test8.tb > tests/test8.c
	./calc < tests/test9.tb > tests/test9.c
	./calc < tests/test11.tb > tests/test11.c
	./calc < tests/test12.tb > tests/test12.c
	./calc < tests/test13.tb > tests/test13.c
	./calc < tests/test14.tb > tests/test14.c
	./calc < tests/test15.tb > tests/test15.c
	./calc < tests/test16.tb > tests/test16.c
	./calc < tests/test17.tb > tests/test17.c
#	./calc < tests/test20.tb > tests/test20.c
#	./calc < tests/test7.tb > tests/test7.c

# Depedencies from ocamldep
calc.cmo : cpp.cmo instantiation.cmo unification.cmo scanner.cmo parser.cmi ast.cmi
calc.cmx : cpp.cmx instantiation.cmx unification.cmx scanner.cmx parser.cmx ast.cmi
cpp.cmo : cpp.cmi instantiation.cmx unification.cmo scanner.cmo parser.cmi ast.cmi
cpp.cmx : cpp.cmi instantiation.cmi unification.cmx scanner.cmx parser.cmx ast.cmi
cpp.mli : instantiation.cmi unification.cmi ast.cmi
instantiation.cmo : instantiation.cmi unification.cmo scanner.cmo parser.cmi ast.cmi
instantiation.cmx : instantiation.cmi unification.cmx scanner.cmx parser.cmx ast.cmi
instantiation.mli : unification.cmi ast.cmi
unification.cmo : unification.cmi scanner.cmo parser.cmi ast.cmi
unification.cmx : unification.cmi scanner.cmx parser.cmx ast.cmi
unification.mli : ast.cmi
parser.cmo : ast.cmi parser.cmi
parser.cmx : ast.cmi parser.cmi
scanner.cmo : parser.cmi
scanner.cmx : parser.cmx


##############################


.PHONY : clean
clean :
	rm -rf *.cmi *.cmo parser.ml parser.mli scanner.ml calc tests/*.c tests/a.out parser.output
