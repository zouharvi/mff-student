#include <string>

#ifndef TEXT_UTILS
    #define TEXT_UTILS

    class TextUtils {
        public:
            static std::string to_upper(std::string);
            static std::string to_lower(std::string);
    };

#endif