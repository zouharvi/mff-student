#include "utils/tokenizer.h"
#include <iostream>

std::vector<std::string> Tokenizer::split(std::string_view line)
{
    std::vector<std::string> tokens;
    char quote_mark = '\0';
    bool escaped = false;
    std::string cur_word = "";
    for (size_t i = 0, length = line.length(); i < length; i++)
    {
        if (escaped)
        {
            escaped = false;
            // whitespace doesn't end a word here, so just append it, whatever char it is
            cur_word += line[i];
        }
        else
        {
            escaped = line[i] == '\\'; // if \, just set escaped to true

            if (quote_mark == '\0')
            {
                if (split_char(line[i]) || (i != length - 1 && line[i] == '|' && line[i + 1] == '|'))
                { // operators need to be tokenized separately
                    if (cur_word != "")
                    {
                        tokens.push_back(cur_word);
                        cur_word = "";
                    }
                    if (i != length - 1 && line[i] == '|' && line[i + 1] == '|')
                    { // special treatment for ||
                        tokens.push_back("||");
                        i++;
                    }
                    else if (i != length - 1 && line[i] == '!' && line[i + 1] == '=')
                    { // special treatment for !=
                        tokens.push_back("!=");
                        i++;
                    }
                    else if (i != length - 1 && line[i] == '>' && line[i + 1] == '=')
                    { // special treatment for >=
                        tokens.push_back(">=");
                        i++;
                    }
                    else if (i != length - 1 && line[i] == '<' && line[i + 1] == '=')
                    { // special treatment for <=
                        tokens.push_back("<=");
                        i++;
                    }
                    else
                    {
                        tokens.push_back(std::string(1, line[i]));
                    }
                    continue;
                }

                if (line[i] == '\'' || line[i] == '"')
                { // set up new quote mark
                    quote_mark = line[i];
                    cur_word += line[i];
                }
                else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
                { // whitespace end current word if not empty
                    if (cur_word.length() != 0)
                    {
                        tokens.push_back(cur_word);
                        cur_word = "";
                    }
                }
                else
                {
                    cur_word += line[i]; // otherwise just append to the current word
                }
            }
            else
            {
                if (line[i] == quote_mark)
                { // end quotation
                    quote_mark = '\0';
                    tokens.push_back(cur_word + line[i]);
                    cur_word = "";
                }
                else
                {
                    cur_word += line[i]; // otherwise just append to the current word
                }
            }
        }
    }
    if (cur_word != "")
    {
        tokens.push_back(cur_word);
    }
    return tokens;
}

bool Tokenizer::is_meta(std::string_view line)
{
    return line[0] == '.';
}

bool Tokenizer::is_end_query(std::string_view line)
{
    for (size_t i = line.length() - 1;; i++)
    {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        {
            continue;
        }
        else if (line[i] == ';')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

std::string &Tokenizer::remove_end_query(std::string &line)
{
    for (size_t i = line.length() - 1;; i++)
    {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        {
            continue;
        }
        else if (line[i] == ';')
        {
            line[i] = ' '; // replace with whitespace and quit
            break;
        }
    }

    return line;
}

std::vector<std::vector<std::string>> Tokenizer::extract_queries(const std::vector<std::string> &tokens)
{
    std::vector<std::vector<std::string>> queries;
    std::vector<std::string> buff;
    for (auto s : tokens)
    {
        if (s[s.length() - 1] == ';')
        {
            queries.push_back(buff);
            buff.clear();
        }
        else
        {
            buff.push_back(s);
        }
    }

    return queries;
}

bool Tokenizer::split_char(char c)
{
    return std::string("()+-/*%,=;><").find(c) != std::string::npos;
}