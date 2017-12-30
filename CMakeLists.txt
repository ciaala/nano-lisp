cmake_minimum_required(VERSION 3.8)
project(nanolisp)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)

set(SOURCE_FILES
        src/include/lexer.h
        src/include/parser.h

        src/executable.cpp
        src/nanolisp.cpp
        src/lexer.cpp
        src/parser.cpp
        src/include/checkers.hpp
        src/checkers/checkers.cpp

        src/interpreter.cpp
        src/include/interpreter.h
        src/include/nanolisp.h
        )
set(REPL_SOURCE_FILES src/main.cpp)


set(GTEST_FILES
        test/test_lexer.cpp
        test/test_parser.cpp
        test/test_interpreter.cpp
        test/test_main.cpp
        )

add_library(nanolisp-lib ${SOURCE_FILES})
target_include_directories(nanolisp-lib INTERFACE src/include)


add_executable(nanolisp ${REPL_SOURCE_FILES})
target_include_directories(nanolisp
        PUBLIC src/include)
target_link_libraries(nanolisp nanolisp-lib)


add_executable(nanolisp-test ${GTEST_FILES})
target_link_libraries(nanolisp-test gtest nanolisp-lib)
target_include_directories(nanolisp-test
        INTERFACE gtest
        PUBLIC test/include
        PUBLIC src/include)

add_test(${GTEST_FILES} nanolisp-test)
