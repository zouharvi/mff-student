#include "models/drop_table.h"

DropTable::DropTable(const std::vector<std::string>& tokens, bool& ok) {
    type = DROP;
    if(tokens.size() != 3) {
        std::cout << "Error: bad DROP syntax (DROP TABLE table_name;)" << std::endl; ok = false;
    } else {
        table_name = tokens[2];
    }
}