#! /bin/bash
mkdir -p bin && g++ -std=c++11 lists_test.cpp -o tests -L/usr/include -lgtest -lgtest_main  -pthread \
 -o bin/test && ./bin/test
