#include "models/column_type.h"

ColumnType::ColumnType(vector<string> tokens, bool& ok) {
    this->name = tokens[0];
    this->type = VarType(CompUtils::slice(tokens, 1, tokens.size() - 1), ok);
}