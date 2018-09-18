#include "compiler/compiler.h"

bool Compiler::process(vector<string> tokens) {
    for(string s: tokens) {
        cout << s << endl;
    }
    Query query(tokens);

    if(query.command != ERROR) {
        return true; // pass to engine processor
    } else {
        return false;
    }
}