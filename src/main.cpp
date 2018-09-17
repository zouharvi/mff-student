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
    } catch(...) {
        exception_ptr p = current_exception();
    }

    return 0;
}
