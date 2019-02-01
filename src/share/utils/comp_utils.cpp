#include "utils/comp_utils.h"

std::string CompUtils::implode(const std::vector<std::string> &vec, const char *delim)
{
    std::stringstream res;
    // CHECK: is this 100% safe in all cases?
    copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(res, delim));
    return res.str();
}

unsigned int CompUtils::parse_uint(std::string_view text, bool &ok)
{
    unsigned int num = 0;
    // max size 9
    if (text.length() >= 9)
    {
        ok = false;
        return 0;
    }

    for (char c : text)
    {
        if (!isdigit(c))
        {
            ok = false;
            return 0;
        }
        num = 10 * num + (int(c) - int('0'));
    }

    return num;
}

// Exceptions shouldn't be part of normal program flow and
// the other solution is too heavy. @ANALYSIS
bool CompUtils::is_number(const std::string &s)
{
    double tmp;
    if (std::stringstream(s) >> tmp)
    {
        return true;
    }
    else
    {
        return false;
    }

    // try
    // {
    //     std::stod(s);
    // }
    // catch (...)
    // {
    //     return false;
    // }

    // return true;
}