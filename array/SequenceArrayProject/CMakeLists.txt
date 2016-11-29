cmake_minimum_required(VERSION 3.5)
project(SequenceArrayProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c SequenceArray.c SequenceArray.h Status.h main.c)
add_executable(SequenceArrayProject ${SOURCE_FILES})