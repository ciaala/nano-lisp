//
// Created by Francesco Fiduccia on 11/04/16.
//

#include "include/test_lexer.h"
#include <iostream>

using namespace std;

bool
nltokenBinaryPredicate(const nl::lex_token *first, const nl::lex_token *second) {
    return *first == *second;
}

bool
check_lexer(bool match, string input, vector<nl::lex_token *> &expected) {
    vector<nl::lex_token *> result;
    nl::lexical(input, result);

    if (match && result.size() != expected.size()) {
        cout << "Expected and result doesn't have the same length" << endl;
        for (auto item : result) {
            cout << nl::lex_symbols.at(item->symbol) << " ";
        }
        cout << endl << endl;
        return false;
    } else if ((!match) ||
               (!equal(result.begin(), result.end(), expected.begin(), expected.end(), nltokenBinaryPredicate))) {

        auto diff = mismatch(result.begin(), result.end(), expected.begin(), expected.end());
        if (*diff.first != *diff.second) {
            cout << nl::lex_symbols.at((*diff.first)->symbol) << " != " <<
            nl::lex_symbols.at((*diff.second)->symbol);
        }
        cout << endl;
        for (auto item : result) {
            cout << nl::lex_symbols.at(item->symbol) << " ";
        }
        cout << endl << endl;
        return false;
    } else {
        cout << "String:" << endl << '\t' << input << endl << "matches as:" << endl << "\t";
        for (auto item : expected) {
            cout << nl::lex_symbols.at(item->symbol) << " ";
        }
        cout << endl << endl;
        return true;
    }

}

int test_lexer_main() {

    vector<nl::lex_token *> result{};
    //check_lexer(true, "", vector<nl::lex_token> {});
    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_string("falcon"),
                                     nl::lex_token::create_rp()};
    check_lexer(true, "(\"falcon\")", result);

    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_string("falcon"),
                                     nl::lex_token::create_string("space-x"),
                                     nl::lex_token::create_rp()};

    check_lexer(true, "(\"falcon\"\"space-x\")", result);


    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_string("falcon"),
                                     nl::lex_token::create_string("space-x"),
                                     nl::lex_token::create_number(123451),
                                     nl::lex_token::create_rp()};

    check_lexer(true, "(\"falcon\"\"space-x\"   123451)", result);

    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_id("Hello"),
                                     nl::lex_token::create_id("World"),

                                     nl::lex_token::create_string("falcon"),
                                     nl::lex_token::create_string("space-x"),
                                     nl::lex_token::create_number(123451),
                                     nl::lex_token::create_rp()};

    check_lexer(true, "(Hello World \"falcon\"\"space-x\"   123451)", result);


    result = vector<nl::lex_token *>{nl::lex_token::create_lp(),
                                     nl::lex_token::create_id("Hello,"),
                                     nl::lex_token::create_id("World!"),

                                     nl::lex_token::create_string("falcon"),
                                     nl::lex_token::create_string("space-x"),
                                     nl::lex_token::create_number(123451),
                                     nl::lex_token::create_rp()};

    check_lexer(false, "(Hello, World! \"falcon\"\"space-x\"   123451)", result);

    return 0;
}
