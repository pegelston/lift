
#include <iostream>
#include "lift/framework/application.h"
#include "gtest/gtest.h"

using namespace lift;

void dummyTest()
{
    ASSERT_EQ(1, 2);
}

int main() 
{
    dummyTest();

    application().create_factory(
        [=](int value, int value2) -> bool
        {
            std::cout << value << " " << value2 << std::endl;
            return true;
        }).run();
}