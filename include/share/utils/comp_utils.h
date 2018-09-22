#include <vector>
#include <string>
#include <sstream>
#include <iterator>

#ifndef COMP_UTILS
    #define COMP_UTILS

    class CompUtils {
        public:
            // joins a vector of string with a delimeter
            static std::string implode(const std::vector<std::string>&, const char*);
            
            // creates a new subvector
            // unfortunately compiled many times over
            template<typename T>
            static std::vector<T> slice(std::vector<T> &v, int m, int n) {
                std::vector<T> vec(n - m + 1);
                copy(v.begin() + m, v.begin() + n + 1, vec.begin());
                return vec;
            }

            // return parsed unsigned int on success; sets bool to false if parse error or nan
            static uint parse_uint(std::string, bool&);
    };
#endif