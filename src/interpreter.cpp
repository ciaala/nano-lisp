//
// Created by Francesco Fiduccia on 13/04/16.
//

#include "include/interpreter.h"
#include <iostream>
#include <sstream>
namespace nl {
    void
    print_parsed(nl_expression *root) {
        cout << "INTERPRETER PARSED: ";
        root->print(cout);
        cout << endl;

    }

    nl_expression*
    interpret(nl_expression *exp) {
        if (exp->isPrimitive()) {
            return exp;
        } else {
            // TODO
            interpret(exp);
        }
    }

    string
    run_interpreter(string &input) {
        nl_expression *root = parse(input);
        print_parsed(root);

        nl_expression* result = interpret(root);

        std::ostringstream stream;
        result->print(stream);
        return stream.str();
    }
}