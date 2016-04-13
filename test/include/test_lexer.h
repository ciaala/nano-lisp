//
// Created by Francesco Fiduccia on 13/04/16.
//
#include <string>
#include <vector>
#include "../../src/include/lexer.h"

#ifndef NANOLISP_TEST_LEXER_H
#define NANOLISP_TEST_LEXER_H
bool
check_lexer(bool match, string input, vector<nl::lex_token *> &expected);

#endif //NANOLISP_TEST_LEXER_H
