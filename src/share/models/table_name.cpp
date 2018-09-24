#include "models/table_name.h"
using namespace std;

TableName::TableName(vector<string> tokens, bool& ok) {
    for(string s : tokens)
        cout << "TNME: " << s << endl;
}