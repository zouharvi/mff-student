#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "zimadb.h"
#include "utils/text_utils.h"
#include "interface/db_connector.h"

class MetaSystem
{
  public:
    MetaSystem(std::string_view, std::shared_ptr<DbConnector>);

    // execute command specified by tokens
    bool process(const std::vector<std::string> &);

    // system vars
    std::string database_file;

    // menu texts
    const std::string HELP_TEXT =
        ".about             Display info about this project\n"
        ".debug [on|off]    Turn debug on/off. Omit arguments for info.\n"
        ".dump TABLE*       Ouput SQL code to dump a whole table (use regex for table name)\n"
        ".exit              Exit this program\n"
        ".help              Show this help\n"
        ".open DATABASE     Open a database file (ends with .zima)\n"
        ".schema TABLE*     Output SQL code to replicate a table schema (use regex for table name)";

    const std::string ABOUT_TEXT =
        "ZimaDB is a from-scratch implementation of some of the SQLite functionality. You can\n"
        "expect some SQL commands to be working, must mostly just a minor subset of them,\n"
        "limited mostly to the simple ones.\n\n"
        "SQL compiler, parser, lexer created by Vilém Zouhar. File format, low level operations\n"
        "designed by Petr Chmel, both MFF students. Created as a semestral project in 2018/2019";

  private:
    // base functions
    void about();
    void debug(const std::vector<std::string> &);
    void dump(const std::vector<std::string> &);
    void exit();
    void help();
    void open(const std::vector<std::string> &);
    void schema(const std::vector<std::string> &);

    // db to communicate open files
    std::shared_ptr<DbConnector> db;
};