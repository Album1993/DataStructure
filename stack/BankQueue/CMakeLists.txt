cmake_minimum_required(VERSION 3.5)
project(BankQueue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c LinkQueue.c LinkQueue.h Status.h SinglyLinkedList.c SinglyLinkedList.h BankQueue.c BankQueue.h Header.h)
add_executable(BankQueue ${SOURCE_FILES})