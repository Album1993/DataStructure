cmake_minimum_required(VERSION 3.5)
project(ExpressionProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c Expression.c Expression.h SequenceStack.c SequenceStack.h Status.h)
add_executable(ExpressionProject ${SOURCE_FILES})