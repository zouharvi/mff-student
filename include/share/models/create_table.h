#include <vector>
#include <string>
#include "query_base.h"
#include "column_type.h"
#include "utils/text_utils.h"
using namespace std;

class CreateTable : public QueryBase {
    public:
        CreateTable(vector<string>, QueryCommand&);
        
        // parsing errors
        void bad_syntax(QueryCommand&); 
        void silent_err(QueryCommand&); 
        
        string table_name;
        vector<ColumnType> columns;
        bool if_not_exists = false; // just supress error if table exists

        // TODO: Possibly add AS select statement? Not too hard to implement.

};