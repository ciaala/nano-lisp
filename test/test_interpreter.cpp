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
        return true;
    }
}

int
test_interpreter_main() {
    string program = "(def a 5)"
            "(def b 6)"
            "(print (sum a b))";
    string output = "11";
    if (check_interpreter(program, output) ){
        cout << program << " interpreted !!!";
    } else {

    }
    return 0;
}