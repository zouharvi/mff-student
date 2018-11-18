#include "compiler/compiler.h"

bool Compiler::process(std::vector<std::string> tokens)
{
    Query query(tokens);

    if (query.ok)
    {
        std::string res = db->perform_query(query);
        std::cout << res << std::endl;

        return true;
    }
    else
    {
        return false;
    }
}
