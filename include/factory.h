
#pragma once

#include <memory>
#include "function_traits.h"

template <typename T>
class factory
{
private:
    using traits = function_traits<T>;
    using result_type = typename traits::result_type;
    using result_type_ptr = std::shared_ptr<result_type>;
    using parameter_tuple_type = typename traits::parameter_tuple_type;
    using parameter_tuple_type_ptr = std::shared_ptr<parameter_tuple_type>;

    T factoryFn;
    parameter_tuple_type_ptr parameters;
    result_type_ptr result;

public:
    factory(T const& fn) :
        factoryFn(fn),
        parameters(std::make_shared<parameter_tuple_type>()),
        result(nullptr)
    {
    }

    void run()
    {
        result = std::make_shared<typename traits::result_type>(factoryFn(std::get<0>(*parameters)));
    }

    parameter_tuple_type_ptr get_parameters()
    {
        return parameters;
    }

    size_t arity()
    {
        return traits::arity;
    }

    result_type_ptr value() const
    {
        return result;
    }
};