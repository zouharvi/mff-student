#include <string>
#include <iostream>
#include "../compiler/compiler.h"
#include "../utils/tokenizer.h"
#include "meta_system.h"
#include <readline/readline.h>
#include <readline/history.h>

class Front {
    public:
        Front();
        void start_loop();

    private:
        // buffer for multiline inputs
        std::string buffer = "";

        // two main processing systems
        Compiler compiler;
        MetaSystem meta_system;

        // main program input loading loop
        void loop(std::string);

        // prompt and load next line
        char* next_line();
        const std::string PROMPT_WORD          = "zimadb> ";
        const std::string PROMPT_WORD_CONTINUE = "   ...> ";

        // program vars
        const std::string VERSION_STR = "0.0.1a";
        
        // user welcome
        const std::string HELLO_USER = "ZimaDB version " + VERSION_STR + "\nEnter `.help` for usage hints.";
        const std::string NO_PERNAMENT_DB = "No .zima file specified. Using `default.zima` instead.";
};