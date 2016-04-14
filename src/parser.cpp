//
// Created by crypt on 4/9/2016.
//

#include <sstream>
#include "include/parser.h"
#include "iostream"

using namespace std;
namespace nl {
    string nl_expression::toString() {
        std::ostringstream stream;
        this->print(stream);
        return stream.str();
    }
    nl_string_expression::nl_string_expression(string &_value) :
            value(_value) {
    }


    nl_expression *parse_list(
            std::vector<lex_token *> &tokens, size_t *i) {
        nl_list_expression *expression = new nl_list_expression;
        size_t start = *i;
        ++(*i);
        while (*i < tokens.size()) {
            lex_token *token = tokens[*i];
            lex_symbol symbol = token->symbol;
            if (symbol == lex_symbol::LP) {
                expression->arguments.push_back(parse_list(tokens, i));
            } else if (symbol == lex_symbol::RP) {
                return expression;
            } else if (symbol == lex_symbol::ID) {
                expression->addArgId(token->id_name);
            } else if (symbol == lex_symbol::STRING) {
                expression->addArgString(token->string_value);
            } else if (symbol == lex_symbol::NUMBER) {
                expression->addArgNumber(token->double_value);
            }
            ++(*i);
        }
        cout << "Unexpectedly reached the end of tokens while parsing a list expression started at token " <<
        tokens[start];
        return NULL;
    }

    nl_expression *parse(string &input) {
        std::vector<lex_token *> tokens;
        lexical(input, tokens);
        nl_list_expression *root = new nl_list_expression;
        root->addArgId("doall");
        for (size_t i = 0; i < tokens.size(); i++) {
            lex_token *token = tokens[i];
            lex_symbol symbol = token->symbol;
            if (symbol == lex_symbol::LP) {
                root->arguments.push_back(parse_list(tokens, &i));
            } else if (symbol == lex_symbol::ID) {
                root->arguments.push_back(new nl_id_expression(token->id_name));
            } else if (symbol == lex_symbol::STRING) {
                root->arguments.push_back(new nl_string_expression(token->string_value));
            } else if (symbol == lex_symbol::NUMBER) {
                root->arguments.push_back(new nl_number_expression(token->double_value));
            }
        }
        nl_expression *result;
        if (root->arguments.size() == 2) {
            // TODO de allocate old root
            result = root->arguments[1];
        } else {
            result = root;
        }
        if (result == nullptr) {
            cout << "Unable to parse the tokens";
        }
        return result;
    }

    nl_number_expression::nl_number_expression(double _value) : value(_value) {

    }

    nl_id_expression::nl_id_expression(string &id) : id(id) { }


    ostream &nl_list_expression::print(ostream &os) {
        os << *this;
        return os;
    }

    ostream &nl_id_expression::print(ostream &os) {
        os << *this;
        return os;
    }

    ostream &nl_number_expression::print(ostream &os) {
        os << *this;
        return os;
    }

    ostream &nl_string_expression::print(ostream &os) {
        os << *this;
        return os;
    }

}

ostream &operator<<(ostream &os, const nl::nl_id_expression &exp) {
    os << "ID(" << exp.id << ")";
    return os;
}

ostream &operator<<(ostream &os, const nl::nl_string_expression &exp) {
    os << "STRING(" << exp.value << ")";
    return os;
}

ostream &operator<<(ostream &os, const nl::nl_number_expression &exp) {
    os << "NUMBER(" << exp.value << ")";
    return os;
}

ostream &operator<<(ostream &os, const nl::nl_list_expression &exp) {
    os << "(";
    for (auto item: exp.arguments) {
        item->print(os);
    }
    os << ")";
    return os;
}

ostream &operator<<(ostream &os, const nl::nl_expression &exp) {
    return os;

}


