cmake_minimum_required(VERSION 3.5)
project(SeqBinaryTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c TestData_Le.txt Scanf.h Scanf.c Status.h  SeqBinaryTree.c SeqBinaryTree.h)
add_executable(SeqBinaryTree ${SOURCE_FILES})