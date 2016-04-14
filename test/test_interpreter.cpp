//
// Created by Francesco Fiduccia on 13/04/16.
//

#include "include/test_interpreter.h"
#include <iostream>

using namespace std;
bool
check_interpreter(string &program, string &expected) {
    string result = nl::run_interpreter(program);
    if (result != expected) {
        cout << "Interpretation has failed. Expected " << expected << " received " << result << endl;
        return false;
    } else {
        cout << program << " interpreted !!!";
        return true;
    }
}

int
test_interpreter_main() {
    string program = "(def a 5)"
            "(def b 6)"
            "(print (sum a b))";
    string output = "11";
    check_interpreter(program, output);


    program = "(def a 5)"
            "(def b 6)"
            "(print (sum a b (sum a b)))";

    output = "22";
    check_interpreter(program, output);


    program = "(def a 5)"
            "(def b 6)"
            "(print (sum a b (sum a b) (sum a 1 2 3 4 5)))";

    output = "42";
    check_interpreter(program, output);

    // SHOULD FAIL

    program = "(def a 5)"
            "(def b 6)"
            /* Missing 1 paranthesis */
            "(print (sum a b (sum a b) (sum a 1 2 3 4 5))";

    output = "42";
    check_interpreter(program, output);
    return 0;
}