#include "models/query.h"
using namespace std;

template <class QueryType> void Query::try_parse(vector<string> tokens) {
    QueryCommand command;
    if(!std::is_base_of<QueryBase, QueryType>()) {
        throw runtime_error("Wrong QueryType type passed to try_parse template.");
    }
    QueryBase* query_data = QueryType(tokens, command).get_data();
    cout << "query type: " << query_data->type << endl;
    if(command == ERROR) {
        this->command = ERROR;
        // TODO: delete query_data  
    } else {
        this->data = query_data;
        this->command = command;
    }
}

Query::Query(vector<string> tokens) {
    if(tokens.size() < 2) {
        cout << "Error: no query has less than two tokens" << endl;
        return;
    } 

    string command1 = TextUtils::to_upper(tokens[0]);
    string command2 = TextUtils::to_upper(tokens[1]);
    if(command1 == "DROP" && command2 == "TABLE")
        try_parse<DropTable>(tokens);
    else if(command1 == "TRUNCATE" && command2 == "TABLE")
        try_parse<TruncateTable>(tokens);
    else if(command1 == "CREATE" && command2 == "TABLE")
        try_parse<CreateTable>(tokens);
    else 
        cout << "Unrecognized query `" << tokens[0] << "`, `" << tokens[1] << "`" << endl;
}