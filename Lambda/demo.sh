#!/bin/bash
./orlang.native  demo/demo"$1".orl  demo/demo"$1".ll
clang demo/demo"$1".ll -Wno-override-module
./a.out > demo/demo"$1".out
rm ./a.out

