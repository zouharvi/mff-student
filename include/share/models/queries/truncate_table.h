#ifndef MODEL_TRUNCATE_TABLE_H
#define MODEL_TRUNCATE_TABLE_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "models/query_base.h"
#include "models/queries/delete.h"
#include "utils/text_utils.h"

class TruncateTable : public QueryBase
{
  public:
    TruncateTable(const std::vector<std::string> &, bool &);
    std::string table_name;
    std::shared_ptr<QueryBase> get_data();

  private:
    std::shared_ptr<Delete> real_query;
};

#endif
