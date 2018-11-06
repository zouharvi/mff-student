#include "front/meta_system.h"
using namespace std;

MetaSystem::MetaSystem(string_view file, std::shared_ptr<DbConnector> db) {
    database_file = file;
    this->db = db;
}

bool MetaSystem::process(const vector<string>& tokens) {
    if(tokens.size() == 0) {
        return false;
    }
    
    if(tokens[0] == "help") help();
    else if(tokens[0] == "about") about();
    else if(tokens[0] == "exit") exit();
    else if(tokens[0] == "open") open(tokens);
    else if(tokens[0] == "debug") debug(tokens);
    else cout << "Unknown command: `" << tokens[0] << "`" << endl;

    return true;
}

void MetaSystem::help() {
    cout << HELP_TEXT << endl;
}

void MetaSystem::about() {
    cout << ABOUT_TEXT << endl;
}

void MetaSystem::exit() {
    // @TODO: is everything cleaned up?
    db->close_file();
    std::exit(0);
}

void MetaSystem::open(const vector<string>& tokens) {
    if(tokens.size() < 2) {
        cout << "Not enough arguments for `.open`. Please specifiy filename." << endl;
    };
    database_file = tokens[1];
    cout << db->open_file(database_file) << endl;;
}

void MetaSystem::debug(const std::vector<std::string>&) {
    cout << "debug:      " << (ZIMADB_DEBUG ? "on" : "off") << endl;
    cout << "database:   " << database_file << endl;
    
    // ZIMADB_DEBUG is now constant
    // @RUDIMENT
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

void MetaSystem::dump(const std::vector<std::string>&) {
    // @TODO: Engine call. Dump all tables if only one param, otherwise regex.
}

void MetaSystem::schema(const std::vector<std::string>&) {
    // @TODO: Engine call. Dump all table schemas if only one param, otherwise regex.
}