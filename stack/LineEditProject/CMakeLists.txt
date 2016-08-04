cmake_minimum_required(VERSION 3.5)
project(LineEditProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c LineEdit.c LineEdit.h Scanf.c Status.h SequenceStack.c SequenceStack.h)
add_executable(LineEditProject ${SOURCE_FILES})