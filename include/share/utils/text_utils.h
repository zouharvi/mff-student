#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#include <string>

class TextUtils
{
  public:
    // converts a string to uppercase/lowercase (copy)
    static std::string to_upper(std::string);
    static std::string to_lower(std::string);

    // compares string, ignoring case size
    static bool cmp(std::string_view, std::string_view);

    // removes one trailing and leading quote, if both exist (and are of the same type)
    static std::string strip_quotes(std::string_view);
};

#endif