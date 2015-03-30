
#pragma once

#include <tuple>

//
// This template allows the deduction of parameter and return type
// of functions. This includes lambdas and specilizations for methods.
//

template < typename T >
struct function_traits :
    public function_traits < decltype(&T::operator()) >
{
    // For generic types, directly use the result of the signature of its 'operator()'
};

// we specialize for pointers to member function
template < typename ClassType, typename ReturnType, typename... Args >
struct function_traits < ReturnType(ClassType::*)(Args...) const >
{
    // arity is the number of arguments.
    enum { arity = sizeof...(Args) };

    using result_type = ReturnType;
    using parameter_tuple_type = std::tuple < Args... > ;

    template < size_t i >
    struct arg
    {
        // the i-th argument is equivalent to the i-th tuple 
        // element of a tuple composed of those arguments.
        using type = typename std::tuple_element< i, std::tuple < Args... > >::type;
    };
};