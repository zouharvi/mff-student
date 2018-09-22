#include <string>
#include <vector>
#include "utils/comp_utils.h"
#include "utils/text_utils.h"
#include "models/var_type.h"

class ColumnType {
    public:
        ColumnType(std::vector<std::string>, bool&);

        // print this object's content
        std::string debug();

        std::string name;
        VarType type;
        bool not_null = false;
        bool primary_key = false;
        enum {ASC, DESC} sort_order = ASC; 
};