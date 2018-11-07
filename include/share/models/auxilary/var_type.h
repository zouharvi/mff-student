#include <string>
#include <vector>
#include <iostream>
#include "utils/comp_utils.h"
#include "utils/text_utils.h"

class VarType
{
  public:
    VarType(const std::vector<std::string> &, bool &);

    // parsing error
    void not_valid(const std::vector<std::string> &, bool &);

    // print this object's content
    std::string to_string();

    enum Type
    {
        INT,
        TINYINT,
        DOUBLE,
        VARCHAR,
        BOOLEAN
    } type;
    size_t size; // applicable only to varchar

  private:
    // get type string name
    std::string get_type_name();
    static const size_t VARCHAR_MAX_SIZE = 1024;
    bool custom_size = false;
};