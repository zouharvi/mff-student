#include "machine.h"

Machine::Machine(const std::string &filename)
{
    file.open(filename);
    if (!file.is_open())
        throw std::runtime_error("Error opening file.");

    std::string line;
    uint i = 1;
    while (getline(file, line))
    {
        try
        {
            instructions.push_back(Lexer::lex_line(line));
        }
        catch (std::exception &e)
        {
            std::cout << "Error on line " << i << ":\n"
                      << e.what() << std::endl;
            file_ok = false;
            break;
        }
        i++;
    }
    if (file_ok)
    {
        // find label definitions
        for (size_t ln = 0; ln < instructions.size(); ln++)
        {
            if (instructions[ln].size() == 0)
                continue;
            if (instructions[ln][0].token_type == Token::LABEL_DEF)
            {
                if (labels.find(instructions[ln][0].label) != labels.end())
                {
                    throw std::runtime_error("This label already exists.");
                }

                labels[instructions[ln][0].label] = ln;

                // remove label definition
                instructions[ln].erase(instructions[ln].begin()); // could be handled more gracefully tho
            }
        }

        while (ip != instructions.size()) // proper end
        {
            // TODO: check IP bounds
            try
            {
                process();
            }
            catch (std::exception &e)
            {
                std::cout << "Error on line " << (ip + 1) << ":\n"
                          << e.what() << std::endl;
                break;
            }
        }
    }
}

void Machine::process()
{
    std::vector<Token> &line = instructions[ip];
    if (line.size() == 0) // empty line
    {
        ip++;
        return;
    }

    // define a new label
    if (line[0].token_type == Token::LABEL_DEF)
    {
        throw std::runtime_error("VM error (label remnant).");
        return;
    }

    if (line[0].token_type != Token::INSTRUCTION)
    {
        throw std::runtime_error("Every non-blank line has to start with a label def or an instruction.");
    }

    // pop
    if (line[0].instruction_type == Token::POP)
    {
        if(stack.size() == 0)
            throw std::runtime_error("POP from an empty stack.");
        stack.pop();
        ip++;
        return;
    }

    // numeric
    if (line[0].instruction_type == Token::ADD || line[0].instruction_type == Token::SUB || line[0].instruction_type == Token::DIV ||
        line[0].instruction_type == Token::MUL || line[0].instruction_type == Token::LT || line[0].instruction_type == Token::GT)
    {
        if (stack.size() < 2)
            throw std::runtime_error("Missing arguments on the stack.");
        if (line.size() > 1)
            throw std::runtime_error("Too many arguments.");
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        switch (line[0].instruction_type)
        {
        case Token::ADD:
            stack.push(a + b);
            break;
        case Token::SUB:
            stack.push(a - b);
            break;
        case Token::DIV:
            // TODO: check b zero
            stack.push(a / b);
            break;
        case Token::MUL:
            stack.push(a * b);
            break;
        case Token::LT:
            stack.push(a > b);
            break;
        case Token::GT:
            stack.push(a < b);
            break;
        }
        ip++;
        return;
    }

    // out
    if (line[0].instruction_type == Token::OUT)
    {
        std::cout << stack.top() << " " << std::endl;
        ip++;
        return;
    }

    // ldconst
    if (line[0].instruction_type == Token::LDCONST)
    {
        if (line.size() != 2)
            throw std::runtime_error("Bad number of arguments.");
        if (line[1].token_type != Token::NUMBER)
            throw std::runtime_error("Bad argument type.");
        stack.push(line[1].num);
        ip++;
        return;
    }

    // stloc, ldloc
    if (line[0].instruction_type == Token::STLOC || line[0].instruction_type == Token::LDLOC)
    {
        if (line.size() != 2)
            throw std::runtime_error("Bad number of arguments.");
        if (line[1].token_type != Token::NUMBER || line[1].num < 0 || line[1].num > 10)
            throw std::runtime_error("Bad argument type.");
        if (line[0].instruction_type == Token::STLOC)
        {
            registers[line[1].num] = stack.top();
            stack.pop();
        }
        else // LDLOC
        {
            stack.push(registers[line[1].num]);
        }
        ip++;
        return;
    }

    if (line[0].instruction_type == Token::GOTO || line[0].instruction_type == Token::BRT || line[0].instruction_type == Token::BRF)
    {
        if (line.size() != 2)
            throw std::runtime_error("Bad number of arguments.");
        if (line[1].token_type != Token::LABEL_REF)
            throw std::runtime_error("Bad argument type.");
        if (labels.find(line[1].label) == labels.end())
            throw std::runtime_error("Given label has not yet been defined.");

        if (line[0].instruction_type == Token::GOTO)
        {
            ip = labels[line[1].label];
            return;
        }

        if (line[0].instruction_type == Token::BRT)
        {
            if (stack.top() != 0) {
                ip = labels[line[1].label];
            }
            else
                ip++;
            return;
        }
        if (line[0].instruction_type == Token::BRF)
        {
            if (stack.top() == 0)
                ip = labels[line[1].label];
            else
                ip++;
            return;
        }
    }
}