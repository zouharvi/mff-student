#include "front.h"
using namespace std;

bool Front::next_line(string& line) {
    cout << PROMPT_WORD;
    return (bool) getline(cin, line);
}

void Front::start_loop() {
    string line;

    while (next_line(line))
    {
        loop(line);
    }
}

bool Front::loop(string& line) {
    
    return true;
}


Front::Front() {
    
}