#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "models/query.h"


#ifndef FILEIO_H
#define FILEIO_H

class FileIO {
    public:
    std::string open_file(std::string);
    void close_file();

    std::string create_table(Query&);
    std::string drop_table(Query&);
    std::string insert(Query&);
    std::string select(Query&);
        
    private:
    enum FILE_VERSION {PROVISIONAL, V1} file_version;
    std::fstream dbfile;
    std::string dbfilename;

    std::fstream rollback_journal;

    /* ----- OPERATIONS ----- */
    bool create_table_provisional(std::unique_ptr<CreateTable>&);
    bool create_table_v1(std::unique_ptr<CreateTable>&) {};

    bool drop_table_provisional(std::unique_ptr<DropTable>&);
    bool drop_table_v1(std::unique_ptr<DropTable>&) {};

    bool insert_provisional(std::unique_ptr<Insert>&);
    bool insert_v1(std::unique_ptr<Insert>&) {};

    std::vector<std::vector<std::string>> select_provisional(std::unique_ptr<Select>&);
    std::vector<std::vector<std::string>> select_v1(std::unique_ptr<Select>&) {};

    std::vector<std::pair<VarType::Type, std::string>> get_column_names_provisional(std::string);
    std::vector<std::string> get_row_data_provisional(std::string);
    
    const std::string PROVISIONAL_FILE_EXTENSION = "pzima";
    const std::string V1_FILE_EXTENSION = "zima";

};

#endif
