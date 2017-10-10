//
// Created by Francesco Fiduccia on 13/04/16.
//

#include "include/test_interpreter.h"
#include <iostream>

using namespace std;


string trim(string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

bool
check_interpreter(string &program, string &expected) {
    string result =nl::run_interpreter(program);
    result = trim(result);
    if (result.compare(expected) != 0) {
        cout << "Interpretation has failed. Expected " << expected << " received " << result << endl;
        return false;
    } else {
        cout << program << " interpreted correctly !!!" << std::endl;
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
            /* Missing 1 parenthesis */
            "(print (sum a b (sum a b) (sum a 1 2 3 4 5))";

    output = "42";
    check_interpreter(program, output);
    return 0;
}