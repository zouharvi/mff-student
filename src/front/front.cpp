#include "front/front.h"

char* Front::next_line() {
    return readline(buffer.length() == 0 ? PROMPT_WORD.c_str() : PROMPT_WORD_CONTINUE.c_str());
}

void Front::start_loop() {
    cout << HELLO_USER << endl;

    // we use char* as a tradeoff for being able to use the readline library
    char* buf;
    while ((buf = next_line()) != nullptr)
    {
        if (strlen(buf) > 0) {
            add_history(buf);
            loop(string(buf));
        }
    }
    cout << endl;
}

bool Front::loop(string line) {
    // if buffer is empty and this is probably a meta command
    if(buffer.length() == 0 && Tokenizer::is_meta(line)) {
        return meta_system.process(Tokenizer::split(line.substr(1)));
    }

    // we accept multiline string, hence this cumbersome process
    buffer += "\n" + line;
    if(Tokenizer::is_end_query(line)) {
        bool response = compiler.process(Tokenizer::split(buffer));
        buffer = "";
        return response;
    } 

    return true;
}

Front::Front() {
    
}