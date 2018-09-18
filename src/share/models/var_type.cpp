#include "models/var_type.h"

VarType::VarType(string raw, bool& ok) {
    ok = true;
    type = INT;
    // TODO: not implemented
}

void VarType::not_valid(const string& raw) {
    cout << "Error: `" << raw << "` is not a valid var type" << endl; 
}

VarType::VarType() { }