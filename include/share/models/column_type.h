#ifndef COLUMN_TYPE_H
#define COLUMN_TYPE_H

#include <string>
#include <vector>
#include "utils/comp_utils.h"
#include "utils/text_utils.h"
#include "models/var_type.h"

class ColumnType {
    public:
        ColumnType(const std::vector<std::string>&, bool&);

        // print this object's content
        const std::string debug();

        // variable name, type
        std::string name;
        VarType type;

        // column type modifiers
        bool not_null = false;
        bool primary_key = false;
        enum {ASC, DESC} sort_order = ASC; 
};

#endif