cmake_minimum_required(VERSION 3.4)
project(Array_Multi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Array_Multi/Arr_Multi.cpp
    stack1/algo3-6.c
    stack1/bo3-1.c
    stack1/c1.h
    stack1/c3-1.h
    string/c4-1.h
    string/string1.c
    "string -1/c4-1.h"
    "string -1/string1.c")

add_executable(Array_Multi ${SOURCE_FILES})