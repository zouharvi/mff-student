#include "models/table_name.h"
using namespace std;

TableName::TableName(vector<string> tokens, bool& ok) {
    if(tokens.size() != 1) {
        ok = false;
        cout << "Error: `" << CompUtils::implode(tokens, " ") << "` is an invalid table name." << endl; 
        return;
    }

    name = tokens[0];
}
TableName::TableName(string name, bool& ok) {
    this->name = name;
}