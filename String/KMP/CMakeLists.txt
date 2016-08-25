cmake_minimum_required(VERSION 3.5)
project(KMP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c Status.h SequenceString.c SequenceString.h KMP.c KMP.h)
add_executable(KMP ${SOURCE_FILES})