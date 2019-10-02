#include <vector>
#include <string>
#include <exception>
#include <map>

#include "object.h"

class Machine
{
  public:
    void process_command(const std::vector<std::string> &tokens)
    {
        if (tokens.size() == 0) // empty line
            return;
        if (tokens.size() == 1)
            throw std::runtime_error("Syntax error"); // There aren't any commands of size 1

        // tokens.size() >= 2
        if (tokens[0] == "print")
            print(tokens);
        else if (tokens[1] == "=")
            assign(tokens);
        else
            throw std::runtime_error("Syntax error"); // Unknown command
    }

  private:
    void print(const TokensVec &tokens)
    {
        if (tokens.size() != 2)
            throw std::runtime_error("Syntax error"); // Too many arguments for print
        Object::fetch(tokens[1], vars)->print();
        std::cout << std::endl;
    }

    void assign(const TokensVec &tokens)
    {
        if (!Tokenizer::check_var_name(tokens[0]))
            throw std::runtime_error("Syntax error"); // Incorrect variable name

        if (tokens.size() == 3)
            vars[tokens[0]] = Object::fetch(tokens[2], vars);
        else if (tokens.size() == 4 && (tokens[2] == "left" || tokens[2] == "right"))
        {
            if (!Tokenizer::check_var_name(tokens[3]))
                throw std::runtime_error("Invalid operation"); // Not a variable (probably just num)
            if (vars.find(tokens[3]) == vars.end())
                throw std::runtime_error("Unknown variable"); // Not a variable
            else
            {
                if (tokens[2] == "left")
                    vars[tokens[0]] = vars[tokens[3]]->get_left();
                else // tokens[2] == "right"
                    vars[tokens[0]] = vars[tokens[3]]->get_right();
            }
        }
        else if (tokens.size() == 5 && tokens[2] == "cell")
        {
            vars[tokens[0]] = Object::create(tokens[3], tokens[4], vars);
        }
        else
            throw std::runtime_error("Syntax error"); // Invalid number of arguments for assignment
    }

    // variable table
    std::map<std::string, ObjectPtr> vars;
};