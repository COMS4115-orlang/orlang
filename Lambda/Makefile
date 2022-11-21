build:
	ocamlbuild orlang.native

tests:
	./orlang < tests/test1.tb > tests/test1.out.c
	./orlang < tests/test2.tb > tests/test2.out.c
	./orlang < tests/test3.tb > tests/test3.out.c
	./orlang < tests/test4.tb > tests/test4.out.c
	./orlang < tests/test5.tb > tests/test5.out.c
	./orlang < tests/test6.tb > tests/test6.out.c
	./orlang < tests/test8.tb > tests/test8.out.c
	./orlang < tests/test9.tb > tests/test9.out.c
	./orlang < tests/test11.tb > tests/test11.out.c
	./orlang < tests/test12.tb > tests/test12.out.c
	./orlang < tests/test13.tb > tests/test13.out.c
	./orlang < tests/test14.tb > tests/test14.out.c
	./orlang < tests/test15.tb > tests/test15.out.c
	./orlang < tests/test16.tb > tests/test16.out.c

##############################

.PHONY : clean
clean :
	rm -rf orlang.native *.cmi *.cmo parser.ml parser.mli scanner.ml orlang tests/*.c tests/a.out parser.output
