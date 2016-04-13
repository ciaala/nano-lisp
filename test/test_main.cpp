//
// Created by Francesco Fiduccia on 13/04/16.
//
#include <iostream>
extern int test_lexer_main();
extern int test_parser_main();
extern int test_interpreter_main();
using  namespace std;

int main() {
    test_lexer_main();
    cout << endl;
    test_parser_main();
    cout << endl;
    test_interpreter_main();
}