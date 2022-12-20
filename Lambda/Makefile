build:
	ocamlbuild -pkgs llvm orlang.native -yaccflag -v

.PHONY : all_tests
all_tests: build
	-./test.sh

.PHONY : demo
demo: build
	-./demo.sh 1
	-./demo.sh 2

##############################

.PHONY : clean
clean :
	rm -rf orlang.native *.cmi *.cmo parser.ml parser.mli scanner.ml orlang tests/*.c tests/*.ll tests/a.out parser.output _build tests/*.out a.out demo/*.ll demo/*.out
