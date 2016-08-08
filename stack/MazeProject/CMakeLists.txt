cmake_minimum_required(VERSION 3.5)
project(MazeProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c  SequenceStack.h SequenceStack.c Status.h Maze.c Maze.c Maze.h)
add_executable(MazeProject ${SOURCE_FILES})