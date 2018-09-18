#include "models/truncate_table.h"

#include <iostream>
using namespace std;

TruncateTable::TruncateTable(vector<string> tokens, string& msg) {
    for(string s : tokens) {
        cout << s << endl;
    }
}