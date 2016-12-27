cmake_minimum_required(VERSION 3.6)
project(SequenceList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c SequenceList.c SequenceList.h main.c Status.h)
add_executable(SequenceList ${SOURCE_FILES})