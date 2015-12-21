
#pragma once

#include "function_traits.h"
#include "index_tuple.h"
#include "parameter_expander.h"

//
// The call() functionality provides a way to call a function
// and pass in a tuple with value types corresponding to that
// functions parameter list.
//

namespace lift {

    template < typename F, typename Tuple >
    auto call(F const& f, Tuple&& t) -> typename meta::function_traits<F>::result_type
    {
        return internal::parameter_expander<F>::expand(f, std::forward<Tuple>(t));
    }

} // namespace lift