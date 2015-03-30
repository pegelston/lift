
#pragma once

#include <memory>
#include "function_traits.h"

template <typename T>
class factory
{
private:
    using traits = function_traits<T>;
    using result_type_ptr = std::shared_ptr<typename traits::result_type>;
    result_type_ptr result;
    T factoryFn;

public:
    factory(T const& fn) :
        factoryFn(fn)
    {
    }

    void run()
    {
        result = std::make_shared<typename traits::result_type>(factoryFn());
    }

    result_type_ptr value() const
    {
        return result;
    }
};