#ifndef MODEL_QUERY_H
#define MODEL_QUERY_H

#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include <memory>
#include "models/queries/create_table.h"
#include "models/queries/drop_table.h"
#include "models/queries/truncate_table.h"
#include "models/queries/select.h"
#include "models/queries/insert.h"
#include "models/queries/update.h"
#include "models/queries/delete.h"
#include "utils/text_utils.h"

class Query
{
  public:
    Query(const std::vector<std::string> &);
    std::unique_ptr<QueryBase> data;
    bool ok = true;

  private:
    // this shouldn't compile unless QueryType is a subclass of QueryBase
    template <class QueryType>
    void try_parse(const std::vector<std::string> &);
};

#endif
