#include "models/update.h"

Update::Update(const std::vector<std::string> &tokens, bool &ok)
{
    type = UPDATE;
    size_t length = tokens.size();
    if (length < 4)
    {
        bad_syntax(ok);
        return;
    }
    table_name = std::make_unique<TableName>(tokens[1], ok);

    if (!TextUtils::cmp(tokens[2], "SET"))
    {
        bad_syntax(ok);
        return;
    }

    // update expressions
    size_t index = 3;
    std::vector<std::string> buff;
    for (; index < length && !TextUtils::cmp(tokens[index], "WHERE"); index++)
    {
        if (tokens[index] == ",")
        {
            if (buff.size() < 3 || buff[1] != "=")
            {
                bad_syntax(ok);
                return;
            }
            columns.push_back(buff[0]);
            expressions.push_back(Expression(std::vector<std::string>(buff.begin() + 2, buff.end()), ok));
            buff.clear();
        }
        else
        {
            buff.push_back(tokens[index]);
        }
    }

    if (!buff.empty())
    {
        if (buff.size() < 3 || buff[1] != "=")
        {
            bad_syntax(ok, buff[1]);
            return;
        }
        columns.push_back(buff[0]);
        expressions.push_back(Expression(std::vector<std::string>(buff.begin() + 2, buff.end()), ok));
        buff.clear();
    }

    if (expressions.empty())
    {
        specific_err(ok, "Error: No update expression specified");
        return;
    }

    if (expressions.size() != columns.size())
    {
        specific_err(ok, "Error: Number of columns does not match the number of given expressions");
        return;
    }

    index++;

    // condition
    if (index < length && tokens[index] == "WHERE")
    {
        condition = std::make_unique<Expression>(CompUtils::slice(tokens, index, length - 1), ok);
    }
}

void Update::bad_syntax(bool &ok, std::string extra)
{
    ok = false;
    std::cout << "Error: Bad UPDATE syntax `UPDATE table_name SET column1 = expression1, column2 = expression2, .. [WHERE condition];`" << std::endl;
    if (extra != "")
    {
        std::cout << "       " << extra << std::endl;
    }
}

void Update::specific_err(bool &ok, std::string extra)
{
    ok = false;
    std::cout << extra << std::endl;
}