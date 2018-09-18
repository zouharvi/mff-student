#include "models/query.h"

Query::Query(vector<string> tokens) {
    string command = TextUtils::to_upper(tokens[0]);
    string msg;
    if(command == "DROP") {
        data.drop = new DropTable(tokens, msg);
        command = DROP;
    } else if(command == "TRUNCATE") {
        data.truncate = new TruncateTable(tokens, msg);
        command = TRUNCATE;
    }
    if(msg != "OK") {
        command = ERROR;
        data.error = &msg;
    }
}