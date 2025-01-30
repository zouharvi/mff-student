#include "front/meta_system.h"

MetaSystem::MetaSystem(std::string_view file, std::shared_ptr<DbConnector> db)
{
    database_file = file;
    this->db = db;
    if (file != "")
    {
        std::cout << db->open_file(database_file) << std::endl;
    }
}

bool MetaSystem::process(const std::vector<std::string> &tokens)
{
    if (tokens.size() == 0)
    {
        return false;
    }

    if (tokens[0] == "help")
        help();
    else if (tokens[0] == "about")
        about();
    else if (tokens[0] == "exit")
        exit();
    else if (tokens[0] == "open")
        open(tokens);
    else if (tokens[0] == "debug")
        debug(tokens);
    else
        std::cout << "Unknown command: `" << tokens[0] << "`" << std::endl;

    return true;
}

void MetaSystem::help()
{
    std::cout << HELP_TEXT << std::endl;
}

void MetaSystem::about()
{
    std::cout << ABOUT_TEXT << std::endl;
}

void MetaSystem::exit()
{
    // @TODO: is everything cleaned up?
    db->close_file();
    std::exit(0);
}

void MetaSystem::open(const std::vector<std::string> &tokens)
{
    if (tokens.size() < 2)
    {
        std::cout << "Not enough arguments for `.open`. Please specifiy filename." << std::endl;
    }
    database_file = tokens[1];
    std::cout << db->open_file(database_file) << std::endl;
}

void MetaSystem::debug(const std::vector<std::string> &)
{
    std::cout << "debug:      " << (ZIMADB_DEBUG ? "on" : "off") << std::endl;
    std::cout << "database:   " << database_file << std::endl;

    // ZIMADB_DEBUG is now constant
    // @UNUSED
    // if(tokens.size() >= 2) {
    //     if(TextUtils::to_upper(tokens[1]) == "ON") {
    //         DEBUG = true;
    //     } else if(TextUtils::to_upper(tokens[1]) == "OFF") {
    //         DEBUG = false;
    //     } else {
    //         cout << "Unknown option: `" << tokens[1] << "`" << endl;;
    //     }
    // }
}

void MetaSystem::dump(const std::vector<std::string> &)
{
    // @TODO: Engine call. Dump all tables if only one param, otherwise regex.
}

void MetaSystem::schema(const std::vector<std::string> &)
{
    // @TODO: Engine call. Dump all table schemas if only one param, otherwise regex.
}