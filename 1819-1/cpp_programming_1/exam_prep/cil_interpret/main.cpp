// started 23:25

#include <iostream>
#include <exception>
#include "machine.h"

int main(int argc, char **argv) {
    for(int i = 1; i < argc; ++i) {
        std::cout << argv[i] << ":" << std::endl;
        try {
            Machine m(argv[i]);
        } catch(std::exception& e) {
            std::cout << e.what() << "\n" << std::endl;
        }
        std::cout << std::endl;
    }
}