//
// Created by crypt on 17/10/17.
//

#ifndef NANOLISP_CHECKERS_HPP
#define NANOLISP_CHECKERS_HPP


//
// Created by Francesco Fiduccia on 13/04/16.
//
#include <string>
#include <vector>
#include "../../src/include/lexer.h"



using namespace std;
bool
check_lexer(bool match, string input, vector<nl::lex_token *> &expected);

#endif //NANOLISP_CHECKERS_HPP