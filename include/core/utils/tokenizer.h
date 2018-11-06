#include <vector>
#include <string>

class Tokenizer {
    public:
        // take in a raw string and output a vector of tokens (strings)
        static std::vector<std::string> split(std::string);

        // meta commands start with a dot (leading whitespace not allowed)
        static bool is_meta(std::string);

        // SQL queries can be multiline and end with a semicolon and arbitrary amount of trailing whitespace
        static bool is_end_query(std::string);

        // remove the last semicolon
        // @UNUSED
        static std::string& remove_end_query(std::string&);
    
        // returns a vector of queries (vector of tokens)
        static std::vector<std::vector<std::string>> extract_queries(const std::vector<std::string>&);

    private:
        // is a specified char a split char?
        static bool split_char(char);
};