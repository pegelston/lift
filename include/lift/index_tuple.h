
#pragma once

namespace lift {
    namespace internal {

        //
        // The index_tuple class allows us to create a parameter
        // pack that we can use to expand the tuple when calling
        // a function.
        //
        template < size_t... >
        struct index_tuple
        {
        };

        template < size_t I, size_t... Indices >
        struct make_indices : make_indices < I - 1, I - 1, Indices... >
        {
        };

        template < size_t... Indices >
        struct make_indices < 0, Indices... >
        {
            using type = typename index_tuple < Indices... >;
        };

    } // namespace internal
} // namespace lift