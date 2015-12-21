
#include <iostream>
#include "lift/static_for.h"

using namespace lift::meta;

struct print_generic
{
    template <typename T>
    void operator()(T const& value) const
    {
        std::cout << value << " ";
    }
};

void test_static_for()
{
    static_for(print_generic(), 0, "hello", 2, 3);
}
