#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <vector>
#include <string>

using TokensVec = std::vector<std::string>;

class Tokenizer
{
  public:
    static std::vector<std::string> tokenize(std::string line)
    {
        std::vector<std::string> tokens;
        std::string buffer = "";

        // @TODO std::stringstream could be more elegant
        for (char c : line)
        {
            if (std::isalnum(c) || c == '$' || c == '=' || c == '-')
                buffer += c;
            else if (c == ' ' || c == '\t')
            {
                if (buffer != "")
                {
                    tokens.push_back(buffer);
                    buffer = "";
                }
            }
            else
            {
                throw std::runtime_error("Sytnax error"); // Unknown characters
            }
        }

        // buffer may still not be empty at the end
        if (buffer != "")
        {
            tokens.push_back(buffer);
            buffer = "";
        }

        return tokens; // @TODO: does gcc really optimize this?
    };

    // ideally \$[0-9a-zA-Z]+
    static bool check_var_name(std::string var)
    {
        if (var.size() < 2)
            return false;
        if (var[0] != '$')
            return false;
        for (size_t i = 1; i < var.length(); i++)
            if (!std::isalnum(var[i]))
                return false;

        return true;
    }
};

#endif