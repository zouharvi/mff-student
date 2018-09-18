#include "models/drop_table.h"

#include <iostream>
using namespace std;

DropTable::DropTable(vector<string> tokens, QueryCommand& command) {
    if(tokens.size() != 3) {
        cout << "Error: bad DROP syntax (DROP TABLE table_name;)" << endl; command = ERROR;
    } else {
        table_name = tokens[2];
    }
}