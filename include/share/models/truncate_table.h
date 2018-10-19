#ifndef TRUNCATE_TABLE_H
#define TRUNCATE_TABLE_H

#include <vector>
#include <string>
#include "query_base.h"
#include "models/delete.h"
#include "utils/text_utils.h"

class TruncateTable : public QueryBase {
    public:
        TruncateTable(std::vector<std::string>, bool&);
        std::string table_name;
        QueryBase* get_data();

    private:
        Delete* real_query;
};

#endif
