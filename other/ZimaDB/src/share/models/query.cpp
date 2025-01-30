#include "models/query.h"

template <class QueryType>
void Query::try_parse(const std::vector<std::string> &tokens)
{
    if (!std::is_base_of<QueryBase, QueryType>())
    {
        throw std::runtime_error("Wrong QueryType type passed to try_parse template.");
    }

    this->data = std::make_unique<QueryType>(tokens, ok);
}

Query::Query(const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
    {
        std::cout << "Error: No query has less than two tokens" << std::endl;
        ok = false;
        return;
    }

    std::string command1 = TextUtils::to_upper(tokens[0]);
    std::string command2 = TextUtils::to_upper(tokens[1]);

    if (command1 == "DROP" && command2 == "TABLE")
        try_parse<DropTable>(tokens);
    else if (command1 == "TRUNCATE" && command2 == "TABLE")
        try_parse<TruncateTable>(tokens);
    else if (command1 == "CREATE" && command2 == "TABLE")
        try_parse<CreateTable>(tokens);
    else if (command1 == "SELECT")
        try_parse<Select>(tokens);
    else if (command1 == "DELETE")
        try_parse<Delete>(tokens);
    else if (command1 == "INSERT")
        try_parse<Insert>(tokens);
    else if (command1 == "UPDATE")
        try_parse<Update>(tokens);
    else
        std::cout << "Unrecognized query `" << tokens[0] << "`, `" << tokens[1] << "`" << std::endl;
}
