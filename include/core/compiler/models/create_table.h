#include <string>
#include <vector>
#include "compiler/models/column_descriptor.h"
using namespace std;

class CreateTable {
    string name;
    vector<ColumnDescriptor> columns;
};