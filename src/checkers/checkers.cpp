//
// Created by crypt on 17/10/17.
//
#include "../include/checkers.hpp"
#include "iostream"

bool
nltokenBinaryPredicate(const nl::lex_token *first, const nl::lex_token *second) {
    return *first == *second;
}

bool
check_lexer(bool match, string input, vector<nl::lex_token *> &expected) {
    vector<nl::lex_token *> result;
    nl::lexical(input, result);

    if (match && result.size() == expected.size()) {
        cout << "String:" << endl << '\t' << input << endl << "matches as:" << endl << "\t";
        for (auto item : expected) {
            cout << nl::lex_symbols.at(item->symbol) << " ";
        }
        cout << endl << endl;
        return true;
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
        cout << "Expected and result doesn't have the same length" << endl;
        for (auto item : result) {
            cout << nl::lex_symbols.at(item->symbol) << " ";
        }
        cout << endl << endl;
        return false;

    }

}
