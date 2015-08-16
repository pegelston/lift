
#pragma once

#include "factory.h"

namespace lift {

    class application
    {
    public:
        application()
        {
        }

        template<typename T>
        factory<T> create_factory(T const& fn)
        {
            return factory<T>(fn);
        }
    };

}