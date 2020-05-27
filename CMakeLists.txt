cmake_minimum_required(VERSION 3.9)
project(Program-C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.cpp structure/test/test.cpp structure/test/test.h structure/stack/sqStack.cpp structure/stack/sqStack.h structure/stack/liStack.cpp structure/stack/run.cpp structure/tree/tree.h structure/tree/tree.cpp structure/tree/run.cpp structure/graph/graph.h structure/graph/graph.cpp)
add_executable(Program-C ${SOURCE_FILES})
