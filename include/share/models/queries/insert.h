#ifndef MODEL_INSERT_H
#define MODEL_INSERT_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <memory>
#include "zimadb.h"
#include "models/query_base.h"
#include "models/auxilary/expression.h"
#include "models/auxilary/table_name.h"
#include "models/auxilary/column_type.h"
#include "utils/text_utils.h"
#include "utils/comp_utils.h"

class Insert : public QueryBase
{
public:
  Insert(const std::vector<std::string> &, bool &);

  // parsing errors
  void bad_syntax(bool &, std::string extra = "");
  void specific_err(bool &, std::string extra = "");

  std::vector<std::string> columns;
  std::vector<Expression> expressions;
  std::unique_ptr<TableName> table_name;

  // @TODO: possible Select
};

#endif