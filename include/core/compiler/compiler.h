#include <string>
#include <vector>
#include <memory>
#include "models/query.h"
#include "interface/db_connector.h"

class Compiler {
    public:
        // creates and executes a query
        bool process(std::vector<std::string>);
        
        Compiler (std::shared_ptr<DbConnector> db) {
            this->db = db;
        };
    
    private:
        std::shared_ptr<DbConnector> db;
};
