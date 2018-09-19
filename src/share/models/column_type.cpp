#include "models/column_type.h"

ColumnType::ColumnType(vector<string> tokens, bool& ok) {
    this->name = tokens[0];
    size_t length = tokens.size();
    size_t end = length -1;
    size_t start = 1;
    if(tokens[end] == "ASC") {
        end -= 1;
        sort_order = ASC;
    } else if(tokens[end] == "DESC") {
        end -= 1;
        sort_order = DESC;
    }
    if(end > 1 && tokens[end] == "KEY" && tokens[end-1] == "PRIMARY") {
        primary_key = true;
        end -= 2;
    }
    if(end > 1 && tokens[end] == "NULL" && tokens[end-1] == "NOT") {
        not_null = true;
        end -= 2;
    }
    this->type = VarType(CompUtils::slice(tokens, start, end), ok);
}

string ColumnType::debug() {
    return name + " : " + type.debug() + (not_null ? " NOT NULL" : "") + (primary_key? (" PRIMARY KEY " + ((string) (sort_order == DESC ? "DESC" : "ASC"))) : "" ); 
}