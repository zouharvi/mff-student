#include "models/query.h"

template <class QueryType> void* Query::try_parse(vector<string> tokens) {
    QueryCommand command;
    QueryBase* query_data = new QueryType(tokens, command);

    if(command == ERROR) {
        this->command = ERROR;
        // TODO: delete query_data  
    } else {
        this->data = query_data;
        this->command = command;
    }
}

Query::Query(vector<string> tokens) {
    string command = TextUtils::to_upper(tokens[0]);
    if(command == "DROP")
        try_parse<DropTable>(tokens);
    else if(command == "TRUNCATE")
        try_parse<TruncateTable>(tokens);
    else 
        cout << "Unrecognized query `" << tokens[0] << "`" << endl;
}