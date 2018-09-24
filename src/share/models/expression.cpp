#include "models/expression.h"
using namespace std;

Expression::Expression(vector<string> tokens, bool& ok) {
    for(string s : tokens)
        cout << "EXPR: " << s << endl;
}