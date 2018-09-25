#include "models/select.h"

using namespace std;

Select::Select(vector<string> tokens, bool& ok) {
    type = SELECT;
    size_t length = tokens.size();
    if(length < 4) {
        bad_syntax(ok); return; // sadly `return void` doesn't work
    }

    // select expressions
    size_t index = 1;
    vector<string> buff;
    for(; index < length && !TextUtils::cmp(tokens[index], "FROM"); index++) {
        if(tokens[index] == ",") {
            expressions.push_back(Expression(buff, ok));
            buff.clear();    
        } else {
            buff.push_back(tokens[index]);
        }
    }

    if(!buff.empty()) {
        expressions.push_back(Expression(buff, ok));
        buff.clear();
    }

    if(expressions.empty()) {
        specific_err(ok, "Error: no select expression specified"); return;
    }

    
    index++;

    // table list
    for(; index < length && !TextUtils::cmp(tokens[index], "WHERE"); index++) {
        if(tokens[index] == ",") {
            table_names.push_back(TableName(buff, ok));
            buff.clear();    
        } else {
            buff.push_back(tokens[index]);
        }
    }

    if(!buff.empty()) {
        table_names.push_back(TableName(buff, ok));
        buff.clear();
    }

    if(table_names.empty()) {
        specific_err(ok, "Error: no table specified"); return;
    }

    index++;

    // condition
    if(index < length) {
        condition = new Expression(CompUtils::slice(tokens, index, length-1), ok);
    }

    map<string, string> vars;
    cout << "EXPRESSION EVAL RESULT: " << expressions[0].eval(vars, ok) << endl;
}

void Select::bad_syntax(bool& ok, string extra) {
    ok = false;
    cout << "Error: Bad SELECT syntax `SELECT expression, ... FROM table_name, ..;`" << endl;
    if (extra != "") {
        cout << "       " << extra << endl;
    }
}

void Select::specific_err(bool& ok, string extra) {
    ok = false;
    cout << extra << endl;
}