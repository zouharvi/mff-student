#include <iostream>
#include <string>
#include <stdexcept>
#include "front/front.h"
#include "random_share_header.h"

using namespace std;

int main() {
    // proof of library linkage

    impress_me();
    try {
        Front front;
        front.start_loop();
    } catch (const std::exception &e) {
        std::cout << e.what() << endl;
    }

    return 0;
}