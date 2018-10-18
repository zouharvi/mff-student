#ifndef CREATE_TABLE_H
#define CREATE_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include "query_base.h"
#include "column_type.h"
#include "utils/text_utils.h"

class CreateTable : public QueryBase {
    public:
        CreateTable(std::vector<std::string>, bool&);
        
        // parsing errors
        void bad_syntax(bool&, std::string extra = ""); 
        void specific_err(bool&, std::string extra = ""); 
        
        ColumnType* primary_key = nullptr;

        std::string table_name;
        std::vector<ColumnType> columns;
        bool as = false; // uses select from other table TODO: not implemented
        bool if_not_exists = false; // just supress error if table exists

        // TODO: Possibly add AS select statement? Not too hard to implement.

};

#endif