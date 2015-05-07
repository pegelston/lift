#include "function_traits.h"
#include "static_for.h"

#include "application.h"
#include "factory.h"

#include <iostream>
#include <string>

using namespace lift;
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

struct for_loop_operator
{
    template <typename T>
    void operator()(T const& value) const
    {
        std::cout << value << std::endl;
    }
};

void test_static_for()
{
    static_for::call(for_loop_operator(), 0, "hello", 2, 3);
}

int main()
{
    auto result = application().create_factory(
        [](int value, int value2, int value3) -> std::string
        {
            std::cout << value << value2 << value3 << std::endl;
            return "success!";
        }).run();

        // Right now we are letting the tuple be initialized with
        // default values, but eventually we want to populate the
        // parameter tuple from a repo of created objects, and feed
        // them to the function in a dependency injection type fashion.

        std::cout << result << std::endl;
}