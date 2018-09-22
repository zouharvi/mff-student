#include "models/truncate_table.h"

#include <iostream>
using namespace std;

TruncateTable::TruncateTable(vector<string> tokens, bool& ok) {
    type = TRUNCATE;
    if(tokens.size() != 3) {
        cout << "Error: bad TRUNCATE syntax (TRUNCATE TABLE table_name;)" << endl; ok = false;
    } else {
        table_name = tokens[2];
    }
}

QueryBase* TruncateTable::get_data() {
    // TODO: translate this into an ordinary delete statement
    return this;
}