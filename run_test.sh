#! /bin/bash

cd test
rm -rf *.o
gcc -c *.c ../array.c ../array_void.c
gcc -o ./test_results *.o
./test_results
rm -rf ./test_results
cd ..
rm -rf ./*.o ./test/*.o