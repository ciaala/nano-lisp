#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace nl {

    class nlvalue {
    public :
        bool getBooleanValue();
    };

    class nlstack {

        vector<unordered_map<string, nlvalue>> scopes;

    public:
        bool contains(string variable) {
            auto iterator = scopes.begin();

            while (iterator != scopes.end() && (*iterator).(variable)) {

            }

        }
    };



    vector<string> tokenizer(string text, char delim, vector<string> &tokens) {
        stringstream stream(text);
        string token;
        while (getline(stream, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }


    nlvalue eval(string input_line) {
        //string special_forms[] = ["if"] ;
        vector<string> tokens;
        tokenizer(input_line, ' ', tokens);
        eval_tokens(stack, tokens);

    }

    class nlspecialform {

    public:
        string token;
        int size;

        virtual nlvalue evaluate() = 0;
    };

    class ifspecialform : nlspecialform {

        nlvalue evaluate(vector<string> tokens) {
            nlvalue condition = eval(tokens.at(1));
            if (condition.getBooleanValue() == true) {
                eval(tokens.at(2));
            } else {
                eval(tokens.at(3));
            }
            return;
        }
    };

    class interpreter {

    private :
        unordered_map<string, nlspecialform> specialForms;
    public:
        interpreter() {
            cout << "Init interpreter" << endl;
            specialForms.insert(nlspecialform);
        }
    };

    void version() {
        cout << info::executable << " is " << info::fullname << info::version << endl;
    }

    void help(int argc, char **argv) {
        version();
    }

    string eval_tokens(nlstack &stack, vector<string> &tokens) {

        if (tokens.size() == 1) {
            // VALUE FORM
            return stack.getValue(tokens.at(0));
        } else if (tokens.size() > 2) {

            if (tokens[0] == '(' & tokens[tokens.size()] == ')') {
                // LIST FORM

            }
        } else {
            // EMPTY FORM
        }

        std::equal(prefix.begin(), prefix.end(), input_line.begin());


    }


    void repl() {
        int line = 0;
        string input_line = "start";
        while (input_line != "end") {
            cout << line << "# ";
            getline(cin, input_line);
            string output_line = eval(input_line);
            cout << ">> " << output_line << endl;
            line++;
        }
    }

    int main(int argc, char **argv) {
        if (argc == 1) {
            version();
            repl();
        }
        else {
            help(argc, argv);

        }
        return 0;
    }
}

int main(int argc, char **argv) {
    return nl::main(argc, argv);
}

