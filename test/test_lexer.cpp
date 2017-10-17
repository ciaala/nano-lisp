//
// Created by crypt on 17/10/17.
//
#include "lexer.h"
#include "checkers.hpp"
#include "gtest/gtest.h"

using namespace std;
vector<nl::lex_token *> result{};

TEST(LEXER, PARENTHESIS_STRING
) {

    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_string("falcon"),
                                     nl::lex_token::create_rp()};
    EXPECT_TRUE(check_lexer(true, "(\"falcon\")", result));
}

TEST(LEXER, PARENTHESIS_TWO_STRINGS
) {
    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_string("falcon"),
                                     nl::lex_token::create_string("space-x"),
                                     nl::lex_token::create_rp()};

    EXPECT_TRUE(check_lexer(true, "(\"falcon\"\"space-x\")", result));
}


TEST(LEXER, PARENTHESIS_TWO_STRINGS_ONE_NUMBER
) {

    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_string("falcon"),
                                     nl::lex_token::create_string("space-x"),
                                     nl::lex_token::create_number(123451),
                                     nl::lex_token::create_rp()};

    EXPECT_TRUE(check_lexer(true, "(\"falcon\"\"space-x\"   123451)", result));
}

TEST(LEXER, PARANTHESIS_TWO_SYMBOLS_TWO_STRINGS_NUMBER
) {

    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_id("Hello"),
                                     nl::lex_token::create_id("World"),

                                     nl::lex_token::create_string("falcon"),
                                     nl::lex_token::create_string("space-x"),
                                     nl::lex_token::create_number(123451),
                                     nl::lex_token::create_rp()};

    EXPECT_TRUE(check_lexer(true, "(Hello World \"falcon\"\"space-x\"   123451)", result));
}

TEST(LEXER, PARANTHESIS_TWO_LINE_STRING
) {
    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_string("falcon\r\nsuper hero"),
                                     nl::lex_token::create_rp()};
    EXPECT_TRUE(check_lexer(true, "(\"falcon\r\nsuper hero\")", result));

}


TEST(LEXER, PARANTHESIS_MULTIPLE_LINES_STRING
) {
    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_string("falcon\r\nsuper\r\nhero"),
                                     nl::lex_token::create_rp()};
    EXPECT_TRUE(check_lexer(true, "(\"falcon\r\nsuper\r\nhero\")", result));

}