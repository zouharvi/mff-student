#include <iostream>
#include <string>
#include <stdexcept>
#include "front/front.h"

int main(int argc, char *argv[]) {
    try {
        // proof of project linkage
        // impress_me();

        // get the first parameter or nothing
        std::string db_name(argc > 1 ? argv[1] : "");
        Front front(db_name);
        front.start_loop();
    } catch (const std::exception &e) {
        std::cout << e.what()  << std::endl;
        std::cout << "Exiting" << std::endl;
        return -1;
    }

    return 0;
}