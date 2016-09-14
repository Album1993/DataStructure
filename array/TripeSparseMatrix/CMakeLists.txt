cmake_minimum_required(VERSION 3.5)
project(TripeSparseMatrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c Scanf.c Status.h TripleSparseMatrix.c TripleSparseMatrix.h TestData.txt)
add_executable(TripeSparseMatrix ${SOURCE_FILES})