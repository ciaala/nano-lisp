#include <iostream>
#include <sstream>
#include <vector>
#include <hash_map>

using namespace std;

namespace nl {

    namespace info {
        string executable = "nl";
        string fullname = "nanolip";
        string version = "";
    }
    class nlvalue {

    };

    class nlstack {

        vector<hash<string, nlvalue>> scopes;

    public:
        bool contains() {
            auto iterator = scopes.begin();

            while (iterator != scopes.end() && (*iterator).) {
            }

        }
    };

    void version() {
        cout << info::executable << " is " << info::fullname << info::version << endl;
    }

    void help(int argc, char **argv) {
        version();
    }


    vector<string> tokenizer(string text, char delim, vector<string> &tokens) {
        stringstream stream(text);
        string token;
        while (getline(stream, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    string eval_tokens(nlstack &stack, vector<string> &tokens) {

        if (tokens.size() == 1) {
            // SINGLE FORM
            return stack.getValue(tokens.at(0));
        } else if () { }

        std::equal(prefix.begin(), prefix.end(), input_line.begin());


    }

    string eval(string input_line) {
        //string special_forms[] = ["if"] ;
        vector<string> tokens;
        tokenizer(input_line, ' ', tokens);


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

