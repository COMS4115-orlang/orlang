.PHONY : build
build:
	ocamlbuild orlang.native

.PHONY : test
test:
	./orlang.native < tests/test$(n).orl > tests/test$(n).out.c

##############################

.PHONY : clean
clean :
	rm -rf orlang.native *.cmi *.cmo parser.ml parser.mli scanner.ml orlang tests/*.c tests/a.out parser.output
