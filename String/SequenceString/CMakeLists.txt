cmake_minimum_required(VERSION 3.5)
project(SequenceString)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES SequenceString.c SequenceString.c SequenceString.h main.c Status.h)
add_executable(SequenceString ${SOURCE_FILES})