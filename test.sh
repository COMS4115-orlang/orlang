#!/bin/bash

for i in {1..63}
do
    echo "running test$i"

    ./orlang.native  tests/test"$i".orl  tests/test"$i".ll 2> tests/test"$i".out

    if [ $? -eq 0 ]; then
        clang tests/test"$i".ll -Wno-override-module -lm
        ./a.out > tests/test"$i".out
    fi

    DIFF=$(diff tests/test"$i".out tests/test"$i".baseline) 

    if [ "$DIFF" != "" ] 
    then
        echo "test$i (llvm translation) failed"
        echo $DIFF
    fi
done
