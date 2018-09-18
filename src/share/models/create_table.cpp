#include "models/create_table.h"

#include <iostream>
using namespace std;

CreateTable::CreateTable(vector<string> tokens, QueryCommand& command) {
    size_t length = tokens.size();
    if(length < 4) {
        bad_syntax(command); return; // sadly `return void` doesn't work
    }
    
    size_t starting_def = 3;
 
    if(tokens[3] != "(") { // must contain IF NOT EXISTS
        if(length < 6 || tokens[2] != "IF" || tokens[3] != "NOT" || tokens[4] != "EXISTS") {
            bad_syntax(command); return;
        } else { // found IF NOT EXISTS
            if_not_exists = true;
            table_name = tokens[5];
            starting_def = 6;
        }
    } else {
        table_name = tokens[2];
    }
    
    if(tokens[starting_def] != "(") { // starting parenthesis not found
        bad_syntax(command); return;
    }

    size_t ending_def = starting_def + 1;

    for(; ending_def < length; ending_def++) {
        if(tokens[ending_def] == ")")
            break;
    }

    if(tokens[ending_def] != ")") { // matching parenthesis not found
        bad_syntax(command); return;
    }

    if(ending_def != length -1) { // some tokens following
        bad_syntax(command); return;
    }

    uint state = 0;
    string column_name;
    for(size_t i = starting_def+1; i < ending_def; i++) {
        if(state == 2 && tokens[i] != ",") {
            bad_syntax(command); return;
        }
        if(state == 0) {
            column_name = tokens[i];
        } else if(state == 1) {
            bool ok;
            columns.push_back(ColumnType(column_name, tokens[i], ok));
            if(!ok) {
                silent_err(command); return;
            }
        }
        state = (state + 1) % 3; // column_name column_def , TODO: datatype is not one token for VARCHAR(n), or attributes
    }

    if(state != 2 || columns.size() == 0) {
            bad_syntax(command); return;
    }

    cout << "DUMPING CREATE TABLE QUERY " << endl;
    cout << "ending state index: " << state << endl;
    cout << "table_name: " << table_name << endl;
    cout << "columns: " << endl;
    for(ColumnType s : columns) {
        cout << s.name << " : " << s.type.type << endl;
    }
    cout << "if_not_exists: " << ((int) if_not_exists) << endl;
}

void CreateTable::bad_syntax(QueryCommand& command) {
    command = ERROR;
    cout << "Error: bad CREATE TABLE syntax (CREATE TABLE [IF NOT EXISTS] table_name ( column_name column_def, .. );)" << endl;
}

void CreateTable::silent_err(QueryCommand& command) {
    command = ERROR;
}