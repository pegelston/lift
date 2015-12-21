
#include <iostream>
#include "lift/application.h"

using namespace lift;

void test_app()
{
    application().create_factory(
        [=](int value, int value2) -> bool
        {
            std::cout << value << " " << value2 << std::endl;
            return true;
        }).run();
}