cmake_minimum_required(VERSION 3.5)
project(CylSeQueueProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c Status.h main.c CycleSeqQueue.c CycleSeqQueue.h)
add_executable(CylSeQueueProject ${SOURCE_FILES})