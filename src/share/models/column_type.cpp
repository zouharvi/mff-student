#include "models/column_type.h"

ColumnType::ColumnType(string name, string type_raw, bool& ok) {
    this->name = name;
    this->type = VarType(type_raw, ok);
}