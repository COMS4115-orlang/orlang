#!/bin/bash
./orlang.native < tests/test"$1".orl > tests/test"$1".c 2> tests/test"$1".out

if [ $? -eq 0 ]; then
    gcc tests/test"$1".c 
    ./a.out > tests/test"$1".out
    DIFF=$(diff tests/test"$1".out tests/test"$1".baseline) 
else
    DIFF=$(diff tests/test"$1".out tests/test"$1".baseline) 
fi

if [ "$DIFF" != "" ] 
then
    echo "test$1 failed"
    echo $DIFF
fi
