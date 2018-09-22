#include <vector>
#include <string>
#include <iostream>
#include "query_base.h"
#include "column_type.h"
#include "utils/text_utils.h"

class CreateTable : public QueryBase {
    public:
        CreateTable(std::vector<std::string>, QueryCommand&);
        
        // parsing errors
        void bad_syntax(QueryCommand&, std::string extra = ""); 
        void silent_err(QueryCommand&); 
        
        std::string table_name;
        std::vector<ColumnType> columns;
        bool as = false; // uses select from other table TODO: not implemented
        bool if_not_exists = false; // just supress error if table exists

        // TODO: Possibly add AS select statement? Not too hard to implement.

};