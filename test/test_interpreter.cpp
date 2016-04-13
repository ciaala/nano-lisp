//
// Created by Francesco Fiduccia on 13/04/16.
//

#include "include/test_interpreter.h"
#include <iostream>
using namespace std;
bool
check_interpreter(string &program, string &expected) {
    string result = nl::run_interpreter(program);
    return ( result == expected );
}

int
test_interpreter_main() {
    string program = "(def a 5)"
            "(def b 6)"
            "(print (sum b c))";
    string output = "11";
    if (check_interpreter(program, output) ){
        cout << program << " interpreted !!!";
    }
    return 0;
}