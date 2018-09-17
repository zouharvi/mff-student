#include "front/meta_system.h"

bool MetaSystem::DEBUG = false;

bool MetaSystem::process(vector<string> tokens) {
    if(tokens.size() == 0) {
        return false;
    }
    
    if(tokens[0] == "help") help();
    else if(tokens[0] == "about") about();
    else if(tokens[0] == "exit") exit();
    else if(tokens[0] == "open") open(tokens);
    else if(tokens[0] == "debug") debug_f(tokens);
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
    // TODO: is everything cleaned up?
    std::exit(0);
}

void MetaSystem::open(vector<string> tokens) {
    if(tokens.size() < 2) {
        cout << "Not enough arguments for `.open`. Please specifiy filename.";
    }
    // TODO: Engine call
}

void MetaSystem::debug_f(vector<string> tokens) {
    if(tokens.size() == 1) {
        cout << "debug:      " << (DEBUG ? "on" : "off") << endl;
        cout << "database:   " << database_file << endl;
    }
    if(tokens.size() >= 2) {
        if(tokens[1] == "on") {
            DEBUG = true;
        } else if(tokens[1] == "off") {
            DEBUG = false;
        } else {
            cout << "Unknown option: `" << tokens[1] << "`" << endl;;
        }
    }
}

void MetaSystem::dump(vector<string> tokens) {
    // TODO: Engine call. Dump all tables if only one param, otherwise regex.
}

void MetaSystem::schema(vector<string> tokens) {
    // TODO: Engine call. Dump all table schemas if only one param, otherwise regex.
}