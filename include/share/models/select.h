#ifndef SELECT_H
#define SELECT_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include "query_base.h"
#include "models/expression.h"
#include "models/table_name.h"
#include "column_type.h"
#include "utils/text_utils.h"
#include "utils/comp_utils.h"

class Select : public QueryBase {
    public:
        Select(std::vector<std::string>, bool&);
        
        // parsing errors
        void bad_syntax(bool&, std::string extra = ""); 
        void specific_err(bool&, std::string extra = ""); 
        
        std::vector<Expression> expressions;
        Expression* condition;
        std::vector<TableName> table_names;
};


#endif