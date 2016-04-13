//
// Created by Francesco Fiduccia on 14/04/16.
//

#ifndef NANOLISP_NANOLISP_H_H
#define NANOLISP_NANOLISP_H_H

#include "parser.h"
#include <unordered_map>
namespace nl {

    class nanolisp_runtime {
    private:
        unordered_map<string, nl_expression*> symbols;
    public:
        nanolisp_runtime();


        static inline nanolisp_runtime* create() {
            return new nanolisp_runtime();
        };

        void add(nl_runtime *runtime);
    };



}
#endif //NANOLISP_NANOLISP_H_H
