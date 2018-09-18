#include "models/drop_table.h"

#include <iostream>
using namespace std;

DropTable::DropTable(vector<string> tokens, string& msg) {
    for(string s : tokens) {
        cout << s << endl;
    }
}