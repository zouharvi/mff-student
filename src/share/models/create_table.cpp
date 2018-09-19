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

    // find this scopes's matching parenthesis
    size_t ending_def = starting_def + 1;
    size_t open = 1;
    for(; ending_def < length; ending_def++) {
        if(tokens[ending_def] == "(") 
            open ++;
        if(tokens[ending_def] == ")") {
            if(open != 1)
                open --;
            else
                break;
        }
    }

    if(tokens[ending_def] != ")") { // matching parenthesis not found
        bad_syntax(command); return;
    }

    if(ending_def != length -1) { // some tokens following
        bad_syntax(command); return;
    }

    vector<string> buff;
    for(size_t i = starting_def+1; i < ending_def; i++) {
        if(i == ending_def -1) {
            buff.push_back(tokens[i]);
        }

        if(tokens[i] == "," || i == ending_def - 1) {
            if(buff.size() < 2) {
                bad_syntax(command); return;
            } else {
                bool ok;
                columns.push_back(ColumnType(buff, ok));
                buff = vector<string>();
                if(!ok) {
                    silent_err(command); return;
                }
            }
        } else {
            buff.push_back(tokens[i]);
        }
    }

    for(ColumnType s : columns) {
        cout << s.name << " : " << s.type.type << " (" << s.type.size << ")" << endl;
    }
}

void CreateTable::bad_syntax(QueryCommand& command) {
    command = ERROR;
    cout << "Error: bad CREATE TABLE syntax `CREATE TABLE [IF NOT EXISTS] table_name ( column_name column_def, .. );`" << endl;
}

void CreateTable::silent_err(QueryCommand& command) {
    command = ERROR;
}