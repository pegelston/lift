
#pragma once

#include "factory.h"

namespace lift {

    class application
    {
    public:
        application()
        {
        }

        template<typename T, typename R>
        factory<T> create_factory(T const& fn, R const& r = R())
        {
            return factory<T>(fn, r);
        }
    };

} // namespace lift