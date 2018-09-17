#include "tokenizer.h"


vector<string> Tokenizer::split(string line) {

}

bool Tokenizer::is_meta(string line) {
    return line[0] == '.';
}

bool Tokenizer::is_end_query(string line) {
    return false;
}