cmake_minimum_required(VERSION 3.3)
#project(test_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD_1 main.c)
set(SOURCE_FILES_1 DataStruct/helloworld.c) #//where main.cc is your first main/program
add_executable(${BUILD_1} ${SOURCE_FILES_1})