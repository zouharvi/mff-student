#include "utils/comp_utils.h"
using namespace std;

string CompUtils::implode(const vector<string>& vec, const char* delim) {
    stringstream res;
    copy(vec.begin(), vec.end(), ostream_iterator<string>(res, delim));
    return res.str();
}

uint CompUtils::parse_uint(string text, bool& ok) {
    uint num = 0;
    if(text.length() >= 9) {
        ok = false;
        return 0;
    }

    for(char c : text) {
        if(!isdigit(c)) {
            ok = false;
            return 0;
        }
        num = 10* num +  ( int(c) - int('0'));
    }

    return num;
}
