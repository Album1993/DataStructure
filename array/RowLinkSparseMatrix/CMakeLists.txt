cmake_minimum_required(VERSION 3.5)
project(RowLinkSparseMatrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c Scanf.c Status.h RowLinkSparseMatrix.c RowLinkSparseMatrix.h)
add_executable(RowLinkSparseMatrix ${SOURCE_FILES})