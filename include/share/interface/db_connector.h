#include <string>

#include "models/query.h"
#include "engine/storage/manager.h"

class DbConnector {
    public:
        std::string perform_query(Query);

    private:
        Manager db_manager;
};