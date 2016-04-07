cmake_minimum_required(VERSION 3.5)
project(nanolisp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp executable.cpp)
add_executable(nanolisp ${SOURCE_FILES})