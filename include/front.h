#include <string>
#include <iostream>
using namespace std;

class Front {
    public:
        Front();
        void start_loop();

    private:
        bool loop(string&);
        bool next_line(string&);
        const string PROMPT_WORD = "zimadb> ";
};