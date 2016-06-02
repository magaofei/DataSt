cmake_minimum_required(VERSION 3.5)
project(DataSt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp prim_MinTree.cpp prim_MinTreewiki.cpp Dijkstra_Lichunbao.c)
add_executable(DataSt ${SOURCE_FILES})