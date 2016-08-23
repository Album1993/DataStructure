cmake_minimum_required(VERSION 3.5)
project(HeapString)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c Status.h HeapString.c HeapString.h)
add_executable(HeapString ${SOURCE_FILES})