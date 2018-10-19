#include "compiler/compiler.h"

using namespace std;

bool Compiler::process(vector<string> tokens) {
    Query query(tokens);

    if(query.ok) {
    	db.perform_query(query);
        return true;
        // TODO: pass to engine processor
    } else {
        return false;
    }
}
