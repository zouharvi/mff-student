#include <iostream>
#include <fstream>
#include "tokenizer.h"
#include "machine.h"

void process_stream(std::istream &stream)
{
    // create a new machine for each file / input
    Machine m;
    std::string line_str;
    uint line_num = 1;
    while (std::getline(stream, line_str))
    {
        try {
            std::vector<std::string> tokens = Tokenizer::tokenize(line_str);
            m.process_command(tokens);
        } catch(std::exception& e) {
            std::cout << e.what() << " on line " << line_num << std::endl;
        }
        line_num++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        process_stream(std::cin);
    else
        for (int i = 1; i < argc; i++)
        {
            std::ifstream file;
            file.open(argv[i], std::ios::in);
            if(file.is_open()) {
                process_stream(file);
                file.close();
            }
        }
}