#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

#ifndef COMP_UTILS
    #define COMP_UTILS

    class CompUtils {
        public:
            // joins a vector of string with a delimeter
            static string implode(const vector<string>&, const char*);
            
            // creates a new subvector
            // unfortunately compiled many times over
            template<typename T>
            static vector<T> slice(vector<T> &v, int m, int n) {
                vector<T> vec(n - m + 1);
                copy(v.begin() + m, v.begin() + n + 1, vec.begin());
                return vec;
            }

            // return parsed unsigned int on success; sets bool to false if parse error or nan
            static uint parse_uint(string, bool&);
    };
#endif