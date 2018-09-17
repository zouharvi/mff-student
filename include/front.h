#include <string>
#include <iostream>
#include "compiler.h"
#include "meta_system.h"

using namespace std;

class Front {
    public:
        Front();
        void start_loop();

    private:
        // buffer for multiline inputs
        string buffer = "";

        // two main processing systems
        Compiler compiler;
        MetaSystem meta_system;

        // main program input loading loop
        bool loop(string&);

        // prompt and load next line
        bool next_line(string&);
        const string PROMPT_WORD          = "zimadb> ";
        const string PROMPT_WORD_CONTINUE = "   ...> ";
};