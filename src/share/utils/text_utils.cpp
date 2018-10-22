#include "utils/text_utils.h"
using namespace std;

string TextUtils::to_upper(string s) {
    for (auto & c: s) c = toupper(c);
    return s;
}

string TextUtils::to_lower(string s) {
    for (auto & c: s) c = toupper(c);
    return s;
}

bool TextUtils::cmp(string a, string b) {
    return to_upper(a) == to_upper(b);
}

string TextUtils::strip_quotes(string a) {
    if(a.size() >= 2 &&
        (
            (a[0] == '"'  && a.back() == '"') ||
            (a[0] == '\'' && a.back() == '\'')
        )
    ) {
        return a.substr(1, a.size() - 2);
    }
    return a;
}
