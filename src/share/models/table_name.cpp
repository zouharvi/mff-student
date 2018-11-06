#include "models/table_name.h"

TableName::TableName(const std::vector<std::string> &tokens, bool &ok)
{
    if (tokens.size() != 1)
    {
        ok = false;
        std::cout << "Error: `" << CompUtils::implode(tokens, " ") << "` is an invalid table name." << std::endl;
        return;
    }

    name = tokens[0];
}

TableName::TableName(const std::string &name, bool &ok)
{
    if (name.length() == 0)
    {
        ok = false;
    }
    else
    {
        this->name = name;
    }
}