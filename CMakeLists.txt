cmake_minimum_required(VERSION 3.8)
project(nanolisp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

set(SOURCE_FILES
        src/include/lexer.h
        src/include/parser.h

        src/main.cpp
        src/executable.cpp
        src/nanolisp.cpp
        src/lexer.cpp
        src/parser.cpp

        src/interpreter.cpp
        src/include/interpreter.h
        src/include/nanolisp.h
        )

set(TEST_FILES
        test/include/test_interpreter.h
        test/include/test_lexer.h
        test/test_lexer.cpp
        test/test_parser.cpp

        test/test_main.cpp
        test/test_interpreter.cpp
        )

add_executable(nanolisp ${SOURCE_FILES} ${TEST_FILES})
