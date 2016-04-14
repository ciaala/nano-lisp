//
// Created by Francesco Fiduccia on 13/04/16.
//

#include "include/interpreter.h"
#include "include/nanolisp.h"
#include <iostream>

namespace nl {
    void
    print_parsed(nl_expression *root) {
        cout << "INTERPRETER PARSED: ";
        root->print(cout);
        cout << endl;
    }

    string
    run_interpreter(string &input) {
        nl_expression *root = parse(input);
        print_parsed(root);
        nanolisp_runtime *runtime = nanolisp_runtime::create();

        nl_expression *result = runtime->eval(root);

        return result->toString();
    }
}