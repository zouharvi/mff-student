#ifndef COMP_UTILS_H
#define COMP_UTILS_H

#include <vector>
#include <string>
#include <sstream>
#include <iterator>

class CompUtils {
    public:
        // joins a vector of string with a delimeter
        static std::string implode(const std::vector<std::string>&, const char*);
        
        // creates a new subvector
        // unfortunately compiled many times over in th eheader
        template<typename T>
        static std::vector<T> slice(const std::vector<T> &v, int m, int n) {
            std::vector<T> vec(n - m + 1);
            copy(v.begin() + m, v.begin() + n + 1, vec.begin());
            return vec;
        }

        // return parsed unsigned int on success; sets bool to false if parse error or nan
        static uint parse_uint(std::string_view, bool&);

        // tries to parse string into a double
        // (stod doesn't know string_view, hence const reference)
        static bool is_number(const std::string&);
};

#endif