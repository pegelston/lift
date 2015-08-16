
#include <iostream>
#include "lift/framework/application.h"
#include "gtest/gtest.h"

using namespace lift;

int main() 
{
    application().create_factory(
        [=](int value, int value2) -> bool
        {
            std::cout << value << " " << value2 << std::endl;
            return true;
        }).run();
}