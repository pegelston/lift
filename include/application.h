
#pragma once

#include "factory.h"

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

    void start()
    {

    }
};
