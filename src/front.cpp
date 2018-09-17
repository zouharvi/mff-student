#include "front.h"

bool Front::next_line(string& line) {
    cout << (buffer.length() == 0 ? PROMPT_WORD : PROMPT_WORD_CONTINUE);
    bool result =  (bool) getline(cin, line);

    return result;
}

void Front::start_loop() {
    cout << HELLO_USER << endl;

    string line;
    while (next_line(line))
    {
        loop(line);
    }
}

bool Front::loop(string& line) {
    if(buffer.length() == 0 && Tokenizer::is_meta(line))
        return meta_system.process(Tokenizer::split(line.substr(1)));

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