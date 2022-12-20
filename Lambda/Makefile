build:
	ocamlbuild -pkgs llvm orlang.native -yaccflag -v

.PHONY : all_tests
all_tests: build
	-./test.sh
	
.PHONY : test
test:
	./orlang.native < tests/test$(n).orl > tests/test$(n).out.c

##############################

.PHONY : clean
clean :
	rm -rf orlang.native *.cmi *.cmo parser.ml parser.mli scanner.ml orlang tests/*.c tests/*.ll tests/a.out parser.output _build tests/*.out a.out
