#include "models/queries/insert.h"

Insert::Insert(const std::vector<std::string> &tokens, bool &ok)
{
    type = INSERT;
    size_t length = tokens.size();

    if (length < 8 || !TextUtils::cmp(tokens[0], "INSERT") || !TextUtils::cmp(tokens[1], "INTO"))
    {
        bad_syntax(ok);
        return;
    }
    table_name = std::make_unique<TableName>(TextUtils::strip_quotes(tokens[2]), ok);

    if (tokens[3] != "(")
    {
        bad_syntax(ok, "Missing column name list");
        return;
    }

    // column order list
    size_t index = 4;
    bool next_comma = false;
    while (length > index && tokens[index] != ")")
    {
        if (next_comma)
        {
            if (tokens[index] != ",")
            {
                bad_syntax(ok, "Expected a comma");
                return;
            }
        }
        else
        {
            columns.push_back(tokens[index]);
        }
        next_comma = !next_comma;
        index++;
    }
    if (!next_comma)
    {
        bad_syntax(ok, "Bad column name list");
        return;
    }

    if (index >= length - 1 || tokens[index] != ")")
    {
        bad_syntax(ok);
        return;
    }

    index++;
    if (!TextUtils::cmp(tokens[index], "VALUES"))
    {
        bad_syntax(ok);
        return;
        // @TODO: Possible SELECT extension
    }

    index++;
    if (tokens[index] != "(")
    {
        bad_syntax(ok);
        return;
    }
    index++;

    // insert expressions
    std::vector<std::string> buff;
    for (; index < length && !TextUtils::cmp(tokens[index], ")"); index++)
    {
        if (tokens[index] == ",")
        {
            expressions.push_back(Expression(buff, ok));
            buff.clear();
        }
        else
        {
            buff.push_back(tokens[index]);
        }
    }

    if (!buff.empty())
    {
        expressions.push_back(Expression(buff, ok));
        buff.clear();
    }

    if (expressions.empty())
    {
        specific_err(ok, "Error: No insert expression specified");
        return;
    }

    if (expressions.size() != columns.size())
    {
        specific_err(ok, "Error: Number of columns does not match the number of given expressions");
        return;
    }

    if (ZIMADB_DEBUG)
    {
        std::map<std::string, std::string> vars;
        std::cout << "Insert first expression empty eval: " << expressions[0].eval_cast<std::string>(vars, ok) << std::endl;
    }
}

void Insert::bad_syntax(bool &ok, std::string extra)
{
    ok = false;
    std::cout << "Error: Bad INSERT syntax `INSERT INTO table_name (column_name, ..) VALUES (expression, ...);`" << std::endl;
    if (extra != "")
    {
        std::cout << "       " << extra << std::endl;
    }
}

void Insert::specific_err(bool &ok, std::string extra)
{
    ok = false;
    std::cout << extra << std::endl;
}