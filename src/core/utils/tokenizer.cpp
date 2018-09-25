#include "utils/tokenizer.h"
using namespace std;

vector<string> Tokenizer::split(string line) {
    vector<string> tokens;
    char quote_mark = '\0';
    bool escaped = false;
    string cur_word = "";
    for(size_t i = 0, length = line.length(); i < length; i++) {
        if(escaped) {
            escaped = false;
            // whitespace doesn't end a word here, so just append it, whatever char it is
            cur_word += line[i];
        } else {
            escaped = line[i] == '\\'; // if \, just set escaped to true

            if(quote_mark == '\0') {
                if( (string("()+-/*%,").find(line[i]) != string::npos) || (i != length-1 && line[i] == '|' && line[i+1] == '|') ) { // operators need to be tokenized separately
                    if(cur_word != "") {
                        tokens.push_back(cur_word);
                        cur_word = "";
                    }
                    if(i != length-1 && line[i] == '|' && line[i+1] == '|') { // special treatment for ||
                        tokens.push_back("||");
                        i++;
                    } else {
                        tokens.push_back(string(1, line[i]));
                    }
                    continue;
                }

                if(line[i] == '\'' || line[i] == '"') { // set up new quote mark
                    quote_mark = line[i];
                } else if(line[i] == ' ' || line[i] == '\t' || line[i] == '\n') { // whitespace end current word if not empty
                    if(cur_word.length() != 0) {
                        tokens.push_back(cur_word);
                        cur_word = "";
                    }
                } else {
                    cur_word += line[i]; // otherwise just append to the current word
                }

            } else {
                if(line[i] == quote_mark) { // end quotation
                    quote_mark = '\0';
                    tokens.push_back(cur_word);
                    cur_word = "";
                } else if(line[i] == quote_mark) { // set up new quote mark
                    quote_mark = '\0';
                } else {
                    cur_word += line[i]; // otherwise just append to the current word
                }
            }
        }
    }
    if(cur_word != "") {
        tokens.push_back(cur_word);
    }

    return tokens;
}

bool Tokenizer::is_meta(string line) {
    return line[0] == '.';
}

bool Tokenizer::is_end_query(string line) {
    for(size_t i = line.length() - 1; i >= 0; i++) {
        if(line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            continue;
        } else if(line[i] == ';') {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

string Tokenizer::remove_end_query(string line) {
    for(size_t i = line.length() - 1; i >= 0; i++) {
        if(line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            continue;
        } else if(line[i] == ';') {
            line[i] = ' '; // replace with whitespace and quit
            break;
        }
    }
    return line;
}