//
// Created by Francesco Fiduccia on 11/04/16.
//

#ifndef NANOLISP_LEXER_H_H
#define NANOLISP_LEXER_H_H

#include <string>
#include <vector>

using namespace std;
namespace nl {
    enum lex_symbol {
        NUMBER, STRING, ID, LP, RP

    };

    extern vector< string> lex_symbols;

    class lex_token {
    public:
        lex_symbol symbol;
        size_t start;
        size_t end;
        double double_value;
        string string_value;
        string id_name;
    public:
        lex_token(lex_symbol _symbol);

        lex_token(lex_symbol _symbol, size_t _start, size_t _end);


        inline static lex_token* create_string(string value) {
            lex_token* token = new lex_token(lex_symbol::STRING);
            token->string_value = value;
            return token;
        }

        inline static lex_token* create_number(double value) {
            lex_token* token = new lex_token(lex_symbol::NUMBER);
            token->double_value = value;
            return token;
        }

        inline static lex_token* create_id(string value) {
            lex_token* token = new  lex_token(lex_symbol::ID);
            token->id_name = value;
            return token;
        }

        inline static lex_token* create_lp() {
            lex_token* token = new lex_token(lex_symbol::LP);
            return token;
        }

        inline static lex_token* create_rp() {
            lex_token* token = new  lex_token(lex_symbol::RP);
            return token;
        }
        inline bool operator == (const lex_token &other) const {
            if (this->symbol == other.symbol ) {
                if (this->symbol == STRING) {
                    return this->string_value == other.string_value;
                } else if (this->symbol == ID) {
                    return this->id_name == other.id_name;
                } else if (this->symbol == NUMBER) {
                    return this->double_value == other.double_value;
                } else{
                    return true;
                }

            }
            return false;
        }
        inline bool operator != (const lex_token &other) const {
            return this->symbol != other.symbol;
        }
    };

    void lexical(string &input, vector<lex_token *> &tokens);

}
#endif //NANOLISP_LEXER_H_H
