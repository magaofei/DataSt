cmake_minimum_required(VERSION 3.5)
project(Array_Multi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Arr_Multi.cpp)
add_executable(Array_Multi ${SOURCE_FILES})