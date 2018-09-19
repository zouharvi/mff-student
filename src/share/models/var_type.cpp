#include "models/var_type.h"

VarType::VarType(vector<string> tokens, bool& ok) {
    ok = true;
    type = INT;
    if(tokens[0] == "INT") {
        type = INT;
    } else if(tokens[0] == "TINYINT") {
        type = TINYINT;
    } else if(tokens[0] == "DOUBLE") {
        type = DOUBLE;
    } else if(tokens[0] == "BOOLEAN") {
        type = BOOLEAN;
    } else if(tokens[0] == "VARCHAR") {
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

    if( (custom_size && tokens.size() != 4) || (!custom_size && tokens.size() != 1)) {
        not_valid(tokens, ok); return;
    }
}

void VarType::not_valid(vector<string> tokens, bool& ok) {
    cout << "Error: `" << CompUtils::implode(tokens, " ") << "` is not a valid var type" << endl; 
    ok = false;
}

VarType::VarType() { }