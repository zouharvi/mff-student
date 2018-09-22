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