#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "models/query.h"

#ifndef FILEIO_H
#define FILEIO_H

enum class FILE_STATUS
{
    FAILURE = -1,
    PROVISIONAL,
    V1
};

class FileIO
{
  public:
    FILE_STATUS open_file(std::string);
    std::size_t get_page_size() { return PAGE_SIZE; };
    void close_file();

    // These are only used for the provisional file - the name doesn't suggest that, but it is still checked.
    std::string create_table(Query &);
    std::string drop_table(Query &);
    std::string insert(Query &);
    std::string select(Query &);

    // These are only used for the V1 file
    std::string read_page(std::size_t);
    bool append_page(std::string);
    bool rewrite_page(std::size_t, std::string);

  private:
    enum FILE_VERSION
    {
        PROVISIONAL,
        V1
    } file_version;
    std::fstream dbfile;
    std::string dbfilename;
    std::size_t max_page;

    static constexpr std::size_t PAGE_SIZE = 1024 * 4; // 2^12 bytes, currently a constant but could be changed during runtime later if the DB is more developed

    std::fstream rollback_journal;

    /* ----- OPERATIONS ----- */
    bool create_table_provisional(std::unique_ptr<CreateTable> &);
	bool create_table_v1(std::unique_ptr<CreateTable> &) { return false;  };

    bool drop_table_provisional(std::unique_ptr<DropTable> &);
    bool drop_table_v1(std::unique_ptr<DropTable> &){ return false; };

    bool insert_provisional(std::unique_ptr<Insert> &);
    bool insert_v1(std::unique_ptr<Insert> &){ return false; };

    std::vector<std::vector<std::string>> select_provisional(std::unique_ptr<Select> &);
	std::vector<std::vector<std::string>> select_v1(std::unique_ptr<Select> &) { return std::vector<std::vector<std::string>>();  };

    std::vector<std::pair<VarType::Type, std::string>> get_column_names_provisional(std::string &);
    std::vector<std::string> get_row_data_provisional(std::string &);

    const std::string PROVISIONAL_FILE_EXTENSION = "pzima";
    const std::string V1_FILE_EXTENSION = "zima";
};

#endif
