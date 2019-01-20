#ifndef MODEL_DELETE_H
#define MODEL_DELETE_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <unordered_set>
#include "zimadb.h"
#include "models/query_base.h"
#include "models/auxilary/expression.h"
#include "models/auxilary/table_name.h"
#include "models/auxilary/column_type.h"
#include "utils/text_utils.h"
#include "utils/comp_utils.h"

class Delete : public QueryBase
{
public:
  Delete(const std::vector<std::string> &, bool &);

  // parsing errors
  void bad_syntax(bool &, std::string extra = "");
  void specific_err(bool &, std::string extra = "");

  std::unique_ptr<Expression> condition;
  TableName *table_name;
};

#endif