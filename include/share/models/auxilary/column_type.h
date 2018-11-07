#ifndef MODEL_COLUMN_TYPE_H
#define MODEL_COLUMN_TYPE_H

#include <string>
#include <vector>
#include <memory>
#include "utils/comp_utils.h"
#include "utils/text_utils.h"
#include "models/auxilary/var_type.h"

class ColumnType
{
  public:
    ColumnType(const std::vector<std::string> &, bool &);

    // print this object's content
    std::string to_string();

    // variable name, type
    std::string name;
    std::unique_ptr<VarType> type;

    // column type modifiers
    bool not_null = false;
    bool primary_key = false;
    enum
    {
        ASC,
        DESC
    } sort_order = ASC;
};

#endif