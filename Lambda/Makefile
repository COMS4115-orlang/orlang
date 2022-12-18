build:
	ocamlbuild -pkgs llvm orlang.native

.PHONY : all_tests
all_tests: build
	-./test.sh 1
	-./test.sh 2
	-./test.sh 3
	-./test.sh 4
	-./test.sh 5
	-./test.sh 6
	-./test.sh 7
	-./test.sh 8
	-./test.sh 9
	-./test.sh 10
	-./test.sh 11
	-./test.sh 12
	-./test.sh 13
	-./test.sh 14
	-./test.sh 15
	-./test.sh 16
	-./test.sh 17
	-./test.sh 18
	-./test.sh 19
	-./test.sh 20
	-./test.sh 21
	-./test.sh 22
	-./test.sh 23
	-./test.sh 24
	-./test.sh 25
	-./test.sh 26
	-./test.sh 27
	-./test.sh 28
	
.PHONY : test
test:
	./orlang.native < tests/test$(n).orl > tests/test$(n).out.c

##############################

.PHONY : clean
clean :
	rm -rf orlang.native *.cmi *.cmo parser.ml parser.mli scanner.ml orlang tests/*.c tests/*.ll tests/a.out parser.output _build tests/*.out a.out
