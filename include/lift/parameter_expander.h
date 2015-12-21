
#pragma once

namespace lift {
    namespace internal {

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
            template < typename F, typename Tuple >
            static ReturnType expand(F const& f, Tuple&& t)
            {
                // Create a parameter pack of indices and use that to expand the
                // tuple into a parameter pack to be passed to the function.
                return call(f, t, typename make_indices<sizeof...(Args)>::type());
            }

            template < typename F, typename Tuple, size_t... Indices >
            static ReturnType call(F const& f, Tuple&& t, index_tuple<Indices...>)
            {
                // Call the function with the expanded tuple.
                return f(std::get<Indices>(std::forward<Tuple>(t))...);
            }
        };

    } // namespace internal
} // namespace lift