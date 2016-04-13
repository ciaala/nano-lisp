//
// Created by crypt on 4/8/2016.
//

#include "include/nanolisp.h"
#include <iostream>
#include <sstream>

namespace nl {

    class nl_runtime : public nl_expression {
    private:

    public:
        string id;
        virtual ostream &print(ostream &os) override {
            os << "RUNTIME(id)";
            return os;
        }

        virtual bool isPrimitive() override {
            return false;
        }

        virtual nl_expression* run(vector<nl_expression*> arguments) = 0;
    };

    class nl_print_runtime : public nl_runtime {


    public:
        virtual nl_expression *run(vector<nl_expression *> arguments) override {
            std::ostringstream stream;
            while (auto item: arguments) {
                item->print(stream);
            }
            return new nl_string_expression( stream.str());

        }
    };





    nanolisp_runtime::nanolisp_runtime()
    {
        this->add(new nl_print_runtime());
    }

    void nanolisp_runtime::add(nl_runtime *runtime) {
        this->symbols[runtime->id] = runtime;
    }


}