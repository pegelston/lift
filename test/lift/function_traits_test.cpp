
#include <iostream>
#include <string>
#include "lift/function_traits.h"

using namespace lift::meta;

// Does not need to be called, this is checked at compile time.
void test_function_traits()
{
    auto lambda = [](int, float, double) -> int { return 0;  };
    using traits = function_traits < decltype(lambda) > ;

    static_assert(std::is_same<traits::arg<0>::type, int>::value, "arg0 not same");
    static_assert(std::is_same<traits::arg<1>::type, float>::value, "arg1 not same");
    static_assert(std::is_same<traits::arg<2>::type, double>::value, "arg2 not same");
    static_assert(std::is_same<traits::result_type, int>::value, "return not same");
    static_assert(traits::arity == 3u, "arity not same");
}