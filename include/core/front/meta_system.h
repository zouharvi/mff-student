#include <string>
#include <vector>
#include <iostream>
#include "utils/text_utils.h"

using namespace std;

class MetaSystem {
    public:
        bool process(vector<string>);

        // system vars
        string database_file;
        static bool DEBUG;

        // menu texts
        const string HELP_TEXT =
            ".about             Display info about this project\n"
            ".debug [on|off]    Turn debug on/off. Omit arguments for info.\n"
            ".dump TABLE*       Ouput SQL code to dump a whole table (use regex for table name)\n"
            ".exit              Exit this program\n"
            ".help              Show this help\n"
            ".open DATABASE     Open a database file (ends with .zima)\n"
            ".schema TABLE*     Output SQL code to replicate a table schema (use regex for table name)";

        const string ABOUT_TEXT =
            "ZimaDB is a from-scratch implementation of some of the SQLite functionality. You can\n"
            "expect some SQL commands to be working, must mostly just a minor subset of them,\n"
            "limited mostly to the simple ones.\n\n"
            "SQL compiler, parser, lexer created by Vilém Zouhar. File format, low level operations\n"
            "designed by Petr Chmel, both MFF students. Created as a semestral project in 2018/2019";

        // base functions
        void about();
        void debug_f(vector<string>);
        void dump(vector<string>);
        void exit();
        void help();
        void open(vector<string>);
        void schema(vector<string>);

};