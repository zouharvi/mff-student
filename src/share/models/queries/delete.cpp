#include "models/queries/delete.h"

Delete::Delete(const std::vector<std::string> &tokens, bool &ok)
{
    type = DELETE;
    size_t length = tokens.size();
    if (length < 2)
    {
        bad_syntax(ok);
        return; // sadly `return void` doesn't work
    }

    // table name
    if (length == 2)
    {
        table_name = new TableName(tokens[1], ok);
    }
    else
    {
        if (!TextUtils::cmp(tokens[1], "FROM"))
        {
            bad_syntax(ok);
            return;
        }
        table_name = new TableName(tokens[2], ok);
    }

    // conditions
    if (length >= 4 && TextUtils::cmp(tokens[3], "WHERE"))
    {
        // condition present
        if (length == 4)
        {
            bad_syntax(ok);
            return;
        }
        condition = std::make_unique<Expression>(CompUtils::slice(tokens, 4, length - 1), ok);
    }
    else
    {
        if (length >= 4)
        {
            bad_syntax(ok);
            return;
        }
        // create virtual condition, that permits everything
        condition = std::make_unique<Expression>(std::vector<std::string>{"1"}, ok);
    }

    if (ZIMADB_DEBUG)
    {
        std::map<std::string, std::string> vars;
        std::cout << "Delete condition empty eval: " << condition->eval_cast<bool>(vars, ok) << std::endl;
    }
}

void Delete::bad_syntax(bool &ok, std::string extra)
{
    ok = false;
    std::cout << "Error: Bad DELETE syntax `DELETE FROM table_name [WHERE condition];`" << std::endl;
    if (extra != "")
    {
        std::cout << "       " << extra << std::endl;
    }
}

void Delete::specific_err(bool &ok, std::string extra)
{
    ok = false;
    std::cout << extra << std::endl;
}