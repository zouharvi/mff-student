#ifndef DROP_TABLE_H
#define DROP_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include "query_base.h"
#include "utils/text_utils.h"

class DropTable : public QueryBase {
    public:
        DropTable(const std::vector<std::string>&, bool&);
        std::string table_name;
};

#endif