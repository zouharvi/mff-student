#include "models/queries/truncate_table.h"

TruncateTable::TruncateTable(const std::vector<std::string> &tokens, bool &ok)
{
    type = TRUNCATE;
    if (tokens.size() != 3)
    {
        std::cout << "Error: bad TRUNCATE syntax (TRUNCATE TABLE table_name;)" << std::endl;
        ok = false;
    }
    else
    {
        table_name = tokens[2];
    }

    // real_query = std::make_shared<Delete>(std::vector<std::string>{"DELETE", "FROM", table_name}, ok);
}

// std::shared_ptr<QueryBase> TruncateTable::get_data()
// {
//     return real_query;
// }