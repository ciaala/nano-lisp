//
// Created by Francesco Fiduccia on 13/04/16.
//
#include "gtest/gtest.h"
#include "checkers.hpp"

using namespace std;
using namespace nl;

TEST(PARSER, DEFINITION_OF_VARIABLE) {

    vector<nl::lex_token *>
            expected_lexer = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                                     nl::lex_token::create_id("def"),
                                                     nl::lex_token::create_id("a"),
                                                     nl::lex_token::create_number(5),
                                                     nl::lex_token::create_rp()};

    nl_list_expression *expression = nl_list_expression::create()->
            addArgId("def")->
            addArgString("a")->
            addArgNumber(5);
    EXPECT_TRUE(check_parser("(def a 5)", expected_lexer, expression));
}

TEST(PARSER, DEFINITION_WHICH_SHOULD_NOT_MAKE_SENSE) {

    nl_list_expression *expression = nl_list_expression::create()
            ->addArgId("def")
            ->addArgString("a")
            ->addArgNumber(5)
            ->addArgString("ciao");

    vector<nl::lex_token *> expected_lexer = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                                                     nl::lex_token::create_id("def"),
                                                                     nl::lex_token::create_id("a"),
                                                                     nl::lex_token::create_number(5),
                                                                     nl::lex_token::create_string("ciao"),
                                                                     nl::lex_token::create_rp()};
    check_parser("(def a 5 \"ciao\")", expected_lexer, expression);
}