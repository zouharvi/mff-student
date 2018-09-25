#include <vector>
#include <string>
#include <iostream>
#include "utils/comp_utils.h"

class TableName {
    public:
        TableName(std::vector<std::string>, bool&);
        std::string name;
};