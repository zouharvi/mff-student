#include <iostream>
#include <string>
#include <stdexcept>

#include "front/front.h"

int main(int argc, char *argv[])
{
    try
    {
        // get the first parameter or nothing
        std::string db_name(argc > 1 ? argv[1] : "");
        Front front(db_name);
        front.start_loop();
    }
    catch (const std::exception &e)
    {
        // We don't widely use exceptions (because of the complexity and speed),
        // but some other parts of the library may, so we try to catch those gracefuly.
        std::cout << e.what() << std::endl;
        std::cout << "Exiting" << std::endl;
        return -1;
    }
    catch (...)
    {
        // Other types are unknown to us.
        std::cout << "Unknown error\nExiting" << std::endl;
    }

    return 0;
}