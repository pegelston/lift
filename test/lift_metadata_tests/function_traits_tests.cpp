#include "function_traits.h"
#include "static_for.h"

#include "application.h"
#include "factory.h"

#include <iostream>

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

void test_factory()
{
    auto factoryFn = 
        []() -> int
        {
            return 0;
        };

    application app;
    auto f = app.create_factory(factoryFn);
    f.run();
    auto result = f.value();
    std::cout << *result << std::endl;
}

int main()
{
    test_factory();
}