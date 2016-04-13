//
// Created by Francesco Fiduccia on 13/04/16.
//

#include "../src/include/parser.h"
#include "include/test_lexer.h"
#include "iostream"
using namespace nl;

void
check_parser(string input, vector<nl::lex_token *> &expected_lexer, nl_expression* expected_parser) {
    if ( check_lexer(true, input, expected_lexer) ) {
        nl_expression* result = parse(input);
        cout << "print parsed: ";
        result->print(cout);
        cout << endl;
    }

}

int test_parser_main() {
    vector<nl::lex_token *> expected_lexer{};

     expected_lexer = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_id("def"),
                                     nl::lex_token::create_id("a"),
                                     nl::lex_token::create_number(5),
                                     nl::lex_token::create_rp()};


    nl_list_expression* expression = nl_list_expression::create()->addArgId("def")->addArgString("a")->addArgNumber(5);
    check_parser("(def a 5)",  expected_lexer, expression);


    expected_lexer = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                             nl::lex_token::create_id("def"),
                                             nl::lex_token::create_id("a"),
                                             nl::lex_token::create_number(5),
                                             nl::lex_token::create_string("ciao"),
                                             nl::lex_token::create_rp()};
    expression->addArgString("ciao");
    check_parser("(def a 5 \"ciao\")",  expected_lexer, expression);
    return 0;
}