#include <string>

#ifndef TEXT_UTILS
    #define TEXT_UTILS

    class TextUtils {
        public:
            static std::string to_upper(std::string);
            static std::string to_lower(std::string);
            static bool cmp(std::string, std::string);
            static std::string strip_quotes(std::string);
    };

#endif