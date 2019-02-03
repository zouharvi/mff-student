#ifndef CREATE_TABLE_H
#define CREATE_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <memory>
#include "zimadb.h"
#include "models/query_base.h"
#include "models/auxilary/column_type.h"
#include "utils/text_utils.h"

class CreateTable : public QueryBase
{
public:
  CreateTable(const std::vector<std::string> &, bool &);

  // parsing errors
  void bad_syntax(bool &, std::string extra = "");
  void specific_err(bool &, std::string extra = "");

  std::string table_name;
  std::vector<ColumnType> columns;

  // create table modifiers
  bool if_not_exists = false; // just supress error if table exists
  int primary_key = -1;

  // @TODO: Possibly add AS select statement. Not too hard to implement.
  bool as = false;
};

#endif