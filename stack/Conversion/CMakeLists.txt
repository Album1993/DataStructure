cmake_minimum_required(VERSION 3.5)
project(Conversion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c ConversionN.c ConversionN.h Scanf.c Status.h SequenceStack.h SequenceStack.c main.c)
add_executable(Conversion ${SOURCE_FILES})
