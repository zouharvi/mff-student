#include "models/delete.h"

using namespace std;

Delete::Delete(vector<string> tokens, bool& ok) {
    type = DELETE;
    size_t length = tokens.size();
    if(length < 2) {
        bad_syntax(ok); return; // sadly `return void` doesn't work
    }

    // table name
    if(length == 2) {
        table_name = new TableName(tokens[1], ok);
    } else {
        if(!TextUtils::cmp(tokens[1], "FROM")) {
            bad_syntax(ok); return; 
        }
        table_name = new TableName(tokens[2], ok);
    }

    if(length >= 4 && TextUtils::cmp(tokens[3], "WHERE")) {
        // condition present
        if(length == 4) {
            bad_syntax(ok); return; 
        }
        condition = new Expression(CompUtils::slice(tokens, 4, length-1), ok);
    } else {
        if(length >= 4) {
            bad_syntax(ok); return; 
        }
        // create virtual condition, that permits everything
        condition = new Expression(vector<string> { "1" }, ok);
    }

    map<string, string> vars;
    cout << "CONDITION EVAL RESULT: " << condition->eval_cast<bool>(vars, ok) << endl;
}

void Delete::bad_syntax(bool& ok, string extra) {
    ok = false;
    cout << "Error: Bad DELETE syntax `DELETE FROM table_name [WHERE condition];`" << endl;
    if (extra != "") {
        cout << "       " << extra << endl;
    }
}

void Delete::specific_err(bool& ok, string extra) {
    ok = false;
    cout << extra << endl;
}