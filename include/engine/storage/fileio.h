#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "models/create_table.h"
#include "models/drop_table.h"
#include "models/query.h"
#include "models/select.h"


#ifndef FILEIO_H
#define FILEIO_H

class FileIO {
    public:
    bool open_file(std::string);
    void close_file();

    std::string create_table(Query&);
    std::string drop_table(Query&);
    //std::string select(Select*);
        
    private:
    enum FILE_VERSION {PROVISIONAL, V1} file_version;
    std::fstream dbfile;
    std::string dbfilename;

    std::fstream rollback_journal;

    /* ----- OPERATIONS ----- */
    bool create_table_provisional(CreateTable*);
    bool create_table_v1(CreateTable*) {};

    bool drop_table_provisional(DropTable*);
    bool drop_table_v1(DropTable*) {};

    //std::vector<std::vector<std::string>> select_provisional(Select*);
    //std::vector<std::vector<std::string>> select_v1(Select*);
    
    const std::string PROVISIONAL_FILE_EXTENSION = "pzima";
    const std::string V1_FILE_EXTENSION = "zima";

};

#endif
