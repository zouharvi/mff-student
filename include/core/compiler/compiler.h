#include <string>
#include <vector>
#include "models/query.h"
#include "interface/db_connector.h"

class Compiler {
    public:
        bool process(std::vector<std::string>);

    private:
        DbConnector db;
};
