#include "utils/text_utils.h"

std::string TextUtils::to_upper(std::string s)
{
    for (auto &c : s)
    {
        c = toupper(c);
    }
    return s;
}

std::string TextUtils::to_lower(std::string s)
{
    for (auto &c : s)
    {
        c = toupper(c);
    }
    return s;
}

bool TextUtils::cmp(std::string_view a, std::string_view b)
{
    // check lengths
    if (a.length() != b.length())
    {
        return false;
    }
 
    // check individual chars
    for (size_t i = 0; i < a.length(); i++)
    {
        if (toupper(a[i]) != toupper(b[i]))
        {
            return false;
        }
    }
    
    return true;
}

std::string TextUtils::strip_quotes(std::string_view a)
{
    if (a.size() >= 2 &&
        ((a[0] == '"' && a.back() == '"') ||
         (a[0] == '\'' && a.back() == '\'')))
    {
        return std::string(a.substr(1, a.size() - 2));
    }

    return std::string(a);
}
