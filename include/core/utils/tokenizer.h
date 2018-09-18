#include <vector>
#include <string>

using namespace std;

class Tokenizer {
    public:
        // take in a raw string and output a vector of tokens (strings)
        static vector<string> split(string);

        // meta commands start with a dot (leading whitespace not allowed)
        static bool is_meta(string);

        // SQL queries can be multiline and end with a semicolon and arbitrary amount of trailing whitespace
        static bool is_end_query(string);

        // remove the last semicolon
        static string remove_end_query(string);
};