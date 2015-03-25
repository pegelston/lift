#include "function_traits.h"

void test_function_traits()
{
    auto lambda = [](int, float, double) {};
    using traits = function_traits < decltype(lambda) > ;

    static_assert(std::is_same<traits::arg<0>::type, int>::value, "arg0 not same");
    static_assert(std::is_same<traits::arg<1>::type, float>::value, "arg1 not same");
    static_assert(std::is_same<traits::arg<2>::type, double>::value, "arg2 not same");
}

int main()
{
    // necessary entry point of exe
}