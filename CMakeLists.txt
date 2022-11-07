cmake_minimum_required(VERSION 3.21)
project(ds_test1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ds_test1 main.cpp calculate.cpp calculate.h SqStack.h SqStack.cpp)
