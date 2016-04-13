cmake_minimum_required(VERSION 3.5)
project(nanolisp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES src/main.cpp src/executable.cpp src/nanolisp.cpp src/lexer.cpp src/parser.cpp test/test_lexer.cpp src/include/lexer.h src/include/parser.h test/test_parser.cpp test/include/test_lexer.h test/test_main.cpp src/interpreter.cpp src/include/interpreter.h test/include/test_interpreter.h test/test_interpreter.cpp src/include/nanolisp.h)
add_executable(nanolisp ${SOURCE_FILES})