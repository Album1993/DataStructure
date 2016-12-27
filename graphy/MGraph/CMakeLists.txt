cmake_minimum_required(VERSION 3.6)
project(MGraph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES LinkQueue.c LinkQueue.h Scanf.c Status.h MGraph.c MGraph.h)
add_executable(MGraph ${SOURCE_FILES})