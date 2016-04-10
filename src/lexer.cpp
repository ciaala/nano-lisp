//
// Created by crypt on 4/9/2016.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;
namespace nl {


    enum lex_symbol {
        NUMBER, STRING, ID, LP, RP;
    };

    class lex_token {
    public:
        lex_token(lex_symbol _symbol, int _start, int _end) :
                symbol(_symbol),
                start(_start),
                end(_end) {

        };
        lex_symbol symbol;
        int start;
        int end;
        double double_value;
        string string_value;
        string symbol_name;
    };


    lex_token *
    lexer_symbol(string &input, int start) {
        int i = start;
        char c = input.at(i);
        while (isalnum(c) || c == '_') {
            i++;
            c = input.at(i);
        }
        lex_token *token = new lex_token();
        return token;
    }

    void
    lexical(string &input, vector<lex_symbol *> &tokens) {
        input.
        for (int i = 0; i < input.length(); ++i) {
            char c = input.at(i);
            if (isalpha(c)) {
                // SYMBOL
                lex_token *token = lexer_symbol(input, i);
                tokens.push_back(token);
            } else if (isdigit(c)) {
                // NUMBER
                tokens.push_back();

            } else if (c == '"') {
                // STRING
            } else if (c == '(') {
                lex_token *token = new lex_token(lex_symbol::LP, i, i);
                tokens.push_back(token);
            } else if (c == ')') {
                lex_token *token = new lex_token(lex_symbol::RP, i, i);
                tokens.push_back(token);
            } else if (isblank(c)) {
                // nothing to do
            } else {
                cout << "unrecognized character " << c << ". found in input at";

            }
        }
    };


}