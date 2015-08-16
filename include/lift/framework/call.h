
#pragma once

#include "../metadata/function_traits.h"

//
// The call() functionality provides a way to call a function
// and pass in a tuple with value types corresponding to that
// functions parameter list.
//

namespace lift {
    namespace internal {

        //
        // The index_tuple class allows us to create a parameter
        // pack that we can use to expand the tuple when calling
        // a function.
        //
        template<size_t...>
        struct index_tuple
        {
        };

        template<size_t I, size_t... Indices>
        struct make_indices : make_indices < I - 1, I - 1, Indices...>
        {
        };

        template <size_t... Indices>
        struct make_indices < 0, Indices... >
        {
            using type = typename index_tuple < Indices... > ;
        };

        template < typename T >
        struct parameter_expander :
            public parameter_expander < decltype(&T::operator()) >
        {
            // For generic types, directly use the result of the signature of its 'operator()'
        };

        // We specialize for pointers to member function
        template < typename ClassType, typename ReturnType, typename... Args >
        struct parameter_expander < ReturnType(ClassType::*)(Args...) const >
        {
            template <typename F, typename Tuple>
            static ReturnType expand(F const& f, Tuple&& t)
            {
                // Create a parameter pack of indices and use that to expand the
                // tuple into a parameter pack to be passed to the function.
                return call(f, t, typename make_indices<sizeof...(Args)>::type());
            }

            template <typename F, typename Tuple, size_t... Indices>
            static ReturnType call(F const& f, Tuple&& t, index_tuple<Indices...>)
            {
                // Call the function with the expanded tuple.
                return f(std::get<Indices>(std::forward<Tuple>(t))...);
            }
        };

    } // namespace internal

    template <typename F, typename Tuple>
    auto call(F const& f, Tuple&& t) -> typename meta::function_traits<F>::result_type
    {
        return internal::parameter_expander<F>::expand(f, std::forward<Tuple>(t));
    }

} // namespace lift