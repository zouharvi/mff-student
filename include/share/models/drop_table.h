#include <vector>
#include <string>
#include <iostream>
#include "query_base.h"
#include "utils/text_utils.h"

class DropTable : public QueryBase {
    public:
        DropTable(std::vector<std::string>, bool&);
        std::string table_name;
};