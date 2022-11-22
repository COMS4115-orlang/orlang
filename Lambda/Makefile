.PHONY : build
build:
	ocamlbuild orlang.native

.PHONY : tests
tests:
	-./orlang.native < tests/test1.orl > tests/test1.out.c
	-./orlang.native < tests/test2.orl > tests/test2.out.c
	-./orlang.native < tests/test3.orl > tests/test3.out.c
	-./orlang.native < tests/test4.orl > tests/test4.out.c
	-./orlang.native < tests/test5.orl > tests/test5.out.c
	-./orlang.native < tests/test6.orl > tests/test6.out.c
	-./orlang.native < tests/test8.orl > tests/test8.out.c
	-./orlang.native < tests/test9.orl > tests/test9.out.c
	-./orlang.native < tests/test11.orl > tests/test11.out.c
	-./orlang.native < tests/test12.orl > tests/test12.out.c
	-./orlang.native < tests/test13.orl > tests/test13.out.c
	-./orlang.native < tests/test14.orl > tests/test14.out.c
	-./orlang.native < tests/test15.orl > tests/test15.out.c
	-./orlang.native < tests/test16.orl > tests/test16.out.c
	-./orlang.native < tests/test17.orl > tests/test17.out.c
	#./orlang < tests/test7.tb > tests/test7.out.c
	#./orlang < tests/test10.tb > tests/test10.out.c

.PHONY : test
test:
	./orlang.native < tests/test$(n).orl > tests/test$(n).out.c

##############################

.PHONY : clean
clean :
	rm -rf orlang.native *.cmi *.cmo parser.ml parser.mli scanner.ml orlang tests/*.c tests/a.out parser.output _build *.c *.out
