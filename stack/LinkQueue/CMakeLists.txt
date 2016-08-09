cmake_minimum_required(VERSION 3.5)
project(LinkQueue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c LinkQueue.c LinkQueue.h main.c Status.h)
add_executable(LinkQueue ${SOURCE_FILES})