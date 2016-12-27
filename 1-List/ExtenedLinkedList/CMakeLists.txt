cmake_minimum_required(VERSION 3.5)
project(ExtenedLinkedList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ExtenedLinkedList.c ExtenedLinkedList.h)
add_executable(ExtenedLinkedList ${SOURCE_FILES} ExtenedLinkedList.c ExtenedLinkedList.h)