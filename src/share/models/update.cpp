#include "models/update.h"

using namespace std;

Update::Update(vector<string> tokens, bool& ok) {
    type = UPDATE;
    size_t length = tokens.size();
    if(length < 4) {
        bad_syntax(ok); return;
    }
    table_name = new TableName(tokens[1], ok);

    if(!TextUtils::cmp(tokens[2], "SET")) {
        bad_syntax(ok); return;
    }

    cout << "1" << endl;

    // update expressions
    size_t index = 3;
    vector<string> buff;
    for(; index < length && !TextUtils::cmp(tokens[index], "WHERE"); index++) {
        if(tokens[index] == ",") {
            if(buff.size() < 3 || buff[1] != "=") {
                bad_syntax(ok); return;
            } 
            columns.push_back(buff[0]);
            expressions.push_back(Expression(vector<string>(buff.begin()+2, buff.end()), ok));
            buff.clear();    
        } else {
            buff.push_back(tokens[index]);
        }
    }

    if(!buff.empty()) {
        if(buff.size() < 3 || buff[1] != "=") {
            bad_syntax(ok, buff[1]); return;
        } 
        columns.push_back(buff[0]);
        expressions.push_back(Expression(vector<string>(buff.begin()+2, buff.end()), ok));
        buff.clear();
    }

    if(expressions.empty()) {
        specific_err(ok, "Error: No update expression specified"); return;
    }

    if(expressions.size() != columns.size()) {
        specific_err(ok, "Error: Number of columns does not match the number of given expressions"); return;
    }

    index++;

    // condition
    if(index < length && tokens[index] == "WHERE") {
        condition = new Expression(CompUtils::slice(tokens, index, length-1), ok);
    } 
    
    // map<string, string> vars;
    // cout << expressions[0].eval(vars, ok) << endl;
}

void Update::bad_syntax(bool& ok, string extra) {
    ok = false;
    cout << "Error: Bad UPDATE syntax `UPDATE table_name SET column1 = expression1, column2 = expression2, .. [WHERE condition];`" << endl;
    if (extra != "") {
        cout << "       " << extra << endl;
    }
}

void Update::specific_err(bool& ok, string extra) {
    ok = false;
    cout << extra << endl;
}