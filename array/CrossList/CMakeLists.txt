cmake_minimum_required(VERSION 3.6)
project(CrossList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Scanf.c Status.h CrossList.c CrossList.h main.c TestData.txt)
add_executable(CrossList ${SOURCE_FILES})