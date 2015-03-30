//#include "function_traits.h"
//#include "static_for.h"
//
//#include <iostream>
//
//// Does not need to be called, this is checked at compile time.
//void test_function_traits()
//{
//    auto lambda = [](int, float, double) {};
//    using traits = function_traits < decltype(lambda) > ;
//
//    static_assert(std::is_same<traits::arg<0>::type, int>::value, "arg0 not same");
//    static_assert(std::is_same<traits::arg<1>::type, float>::value, "arg1 not same");
//    static_assert(std::is_same<traits::arg<2>::type, double>::value, "arg2 not same");
//}
//
//struct for_loop_operator
//{
//    template <typename T>
//    void operator()(T const& value) const
//    {
//        std::cout << value << std::endl;
//    }
//};
//
//void test_static_for()
//{
//    static_for::call(for_loop_operator(), 0, "hello", 2, 3);
//}
//
//int main()
//{
//    test_static_for();    
//}