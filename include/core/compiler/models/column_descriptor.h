#include <string>
using namespace std;

enum ColumnType {
    INT, TEXT, DATE, BLOB
};

class ColumnDescriptor {
    string name;
    ColumnType type;
};