cmake_minimum_required(VERSION 3.9)
project(Program-C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_C_STANDARD 11)
#代码中的目录名

#运行文件a
#static
#set(SOURCE_FILES test-static.c order.c)
#set(SOURCE_FILES order.c)

#set(SOURCE_FILES dataStructure.cpp)
#set(SOURCE_FILES structure/stack/stack.c structure/stack/StackFunction.h)
set(SOURCE_FILES structure/stack/stack.cpp structure/stack/stack.h)

add_executable(Program-C ${SOURCE_FILES})
