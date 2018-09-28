#include "models/create_table.h"

using namespace std;

CreateTable::CreateTable(vector<string> tokens, bool& ok) {
    type = CREATE;
    size_t length = tokens.size();
    if(length < 4) {
        bad_syntax(ok); return; // sadly `return void` doesn't work
    }
    
    size_t starting_def = 3;
 
    if(tokens[3] != "(") { // must contain IF NOT EXISTS
        if(length < 6 || tokens[2] != "IF" || tokens[3] != "NOT" || tokens[4] != "EXISTS") {
            bad_syntax(ok, "Nor name or `IF NOT EXISTS` found."); return;
        } else { // found IF NOT EXISTS
            if_not_exists = true;
            table_name = tokens[5];
            starting_def = 6;
        }
    } else {
        table_name = tokens[2];
    }
    
    if(tokens[starting_def] != "(") { // starting parenthesis not found
        bad_syntax(ok, "Starting parenthesis not found."); return;
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
        bad_syntax(ok, "Matching column descriptions parenthesis not found."); return;
    }

    if(ending_def != length -1) { // some tokens following
        bad_syntax(ok, "There are some words following the last correct `)`."); return;
    }

    vector<string> buff;
    for(size_t i = starting_def+1; i < ending_def; i++) {
        if(i == ending_def -1) {
            buff.push_back(tokens[i]);
        }

        if(tokens[i] == "," || i == ending_def - 1) {
            if(buff.size() < 2) {
                bad_syntax(ok, "Column description requires at least two words."); return;
            } else {
                bool ok;
                columns.push_back(ColumnType(buff, ok));
                buff = vector<string>();
                if(!ok) {
                    specific_err(ok); return;
                }
            }
        } else {
            buff.push_back(tokens[i]);
        }
    }

    // check at most one PRIMARY KEY and unique names
    unordered_set<string> column_names;
    for(ColumnType& column : columns) {
        if(column_names.count(column.name) != 0) {
            specific_err(ok, "Error: Multiple columns named `" + column.name + "`"); break;
        } else {
            column_names.insert(column.name);
        }
        if(column.primary_key) {
            if(primary_key != nullptr) {
                specific_err(ok, "Error: Multiple PRIMARY KEYS"); break;
            } else {
                primary_key = &column;
            }
        }
        cout << column.debug() << endl;
    }
}

void CreateTable::bad_syntax(bool& ok, string extra) {
    ok = false;
    cout << "Error: Bad CREATE TABLE syntax `CREATE TABLE [IF NOT EXISTS] table_name ( column_name column_def, .. );`" << endl;
    if (extra != "") {
        cout << "       " << extra << endl;
    }
}

void CreateTable::specific_err(bool& ok, string extra) {
    ok = false;
    cout << extra << endl;
}