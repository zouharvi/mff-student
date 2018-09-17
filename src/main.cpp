#include <iostream>
#include <string>
#include <stdexcept>
#include "front.h"
#include "engine_interface.h"

using namespace std;

int main() {
    // proof of library linkage

    print_hello();
    try {
        Front front;
        front.start_loop();
    } catch (const std::exception &e) {
        std::cout << e.what() << endl;
    }

    return 0;
}