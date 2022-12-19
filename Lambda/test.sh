#!/bin/bash

./orlang.native < tests/test"$1".orl > tests/test"$1".ll 2> tests/test"$1".out

if [ $? -eq 0 ]; then
    clang tests/test"$1".ll -Wno-override-module
    ./a.out > tests/test"$1".out
    DIFF=$(diff tests/test"$1".out tests/test"$1".baseline) 
else
    DIFF=$(diff tests/test"$1".out tests/test"$1".baseline) 
fi

if [ "$DIFF" != "" ] 
then
    echo "test$1 (llvm translation) failed"
    echo $DIFF
fi
