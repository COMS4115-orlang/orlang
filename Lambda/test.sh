#!/bin/bash

for i in {1..63}
do
    echo "running test$i"

    ./orlang.native  tests/test"$i".orl  tests/test"$i".ll 2> tests/test"$i".out

    if [ $? -eq 0 ]; then
        clang tests/test"$i".ll -Wno-override-module
        ./a.out > tests/test"$i".out
    fi

    if [ $i -eq 6 ]; then
        tmp_sout=$(mktemp /tmp/sout)
        tmp_base=$(mktemp /tmp/base)
        cut -c 1-89 tests/test6.out > $tmp_sout
        cut -c 1-89 tests/test6.baseline > $tmp_base

        DIFF=$(diff $tmp_sout $tmp_base) 

        rm "$tmp_sout"
        rm "$tmp_base"
    else
        DIFF=$(diff tests/test"$i".out tests/test"$i".baseline) 
    fi


    if [ "$DIFF" != "" ] 
    then
        echo "test$i (llvm translation) failed"
        echo $DIFF
    fi
done
