#include "compiler/compiler.h"

using namespace std;


bool Compiler::process(vector<string> tokens) {
    Query query(tokens);

    if(query.ok) {
        string res = db->perform_query(query);
        cout << res << endl;

        return true;
    } else {
        return false;
    }
}
