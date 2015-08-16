
#pragma once

#include "call.h"
#include "function_traits.h"

namespace lift {
 
    //
    // This class provides a container for running a factory function
    // used to build up the dependencies within an application.
    //

    template <typename T>
    class factory
    {
    private:
        using traits = meta::function_traits < T > ;
        using result_type = typename traits::result_type;
        using tuple_type = typename traits::tuple_type;

        T f;
        tuple_type parameters;
        result_type result;

    public:
        factory(T const& fn) :
            f(fn),
            parameters(),
            result()
        {
        }

        result_type run()
        {
            return call(f, parameters);
        }
    };

}