#include "utils/text_utils.h"

string TextUtils::to_upper(string s) {
    for (auto & c: s) c = toupper(c);
    return s;
}

string TextUtils::to_lower(string s) {
    for (auto & c: s) c = toupper(c);
    return s;
}