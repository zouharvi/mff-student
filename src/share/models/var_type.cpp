#include "models/var_type.h"
using namespace std;

VarType::VarType(vector<string> tokens, bool& ok) {
    ok = true;
    size_t length = tokens.size();
    if(length == 0) {
        not_valid(tokens, ok); return;
    }

    string type_str = TextUtils::to_upper(tokens[0]);
    if(type_str == "INT") {
        type = INT;
    } else if(type_str == "TINYINT") {
        type = TINYINT;
    } else if(type_str == "DOUBLE") {
        type = DOUBLE;
    } else if(type_str == "BOOLEAN") {
        type = BOOLEAN;
    } else if(type_str == "VARCHAR") {
        type = VARCHAR;
        size = 32;
        if(tokens.size() == 4) {
            if(tokens[1] == "(" && tokens[3] == ")") {
                uint s = CompUtils::parse_uint(tokens[2], ok);
                if(!ok || size > VARCHAR_MAX_SIZE) {
                    not_valid(tokens, ok); return;
                }
                size = s;
                custom_size = true;
            }
        }
    } else {
        not_valid(tokens, ok); return;
    }

    if( (custom_size && length != 4) || (!custom_size && length != 1)) {
        not_valid(tokens, ok); return;
    }
}

void VarType::not_valid(vector<string> tokens, bool& ok) {
    cout << "Error: `" << CompUtils::implode(tokens, " ") << "` is not a valid var type" << endl; 
    ok = false;
}

string VarType::get_type_name() {
    switch(type) {
        case INT: return "INT";
        case DOUBLE: return "DOUBLE";
        case TINYINT: return "TINYINT";
        case BOOLEAN: return "BOOLEAN";
        case VARCHAR: return "VARCHAR";
    }
    return "";
}

string VarType::debug() {
    return get_type_name() + (type == VARCHAR ? "(" + to_string(size) + ")" : "");
}

VarType::VarType() { }