#include "models/column_type.h"

using namespace std;

ColumnType::ColumnType(vector<string> tokens, bool& ok) {
    this->name = tokens[0];
    size_t length = tokens.size();
    size_t end = length -1;
    size_t start = 1;
    if(TextUtils::cmp(tokens[end], "ASC")) {
        end -= 1;
        sort_order = ASC;
    } else if(TextUtils::cmp(tokens[end], "DESC")) {
        end -= 1;
        sort_order = DESC;
    }
    if(end > 1 && TextUtils::cmp(tokens[end],"KEY") && TextUtils::cmp(tokens[end-1], "PRIMARY")) {
        primary_key = true;
        end -= 2;
    }
    if(end > 1 && TextUtils::cmp(tokens[end], "NULL") && TextUtils::cmp(tokens[end-1], "NOT")) {
        not_null = true;
        end -= 2;
    }
    this->type = VarType(CompUtils::slice(tokens, start, end), ok);
}

const string ColumnType::debug() {
    return name + " : " + type.debug() + (not_null ? " NOT NULL" : "") + (primary_key? (" PRIMARY KEY " + ((string) (sort_order == DESC ? "DESC" : "ASC"))) : "" ); 
}