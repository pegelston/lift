
#pragma once

#include "call.h"
#include "function_traits.h"
#include "object_repository.h"

namespace lift {

    //
    // This class provides a container for running a factory function
    // used to build up the dependencies within an application.
    //

    template <typename FactoryCallback>
    class factory
    {
    private:
        using traits = meta::function_traits<FactoryCallback>;
        using result_type = typename traits::result_type;
        using tuple_type = typename traits::tuple_type;

        FactoryCallback factory_cb;
        tuple_type parameters;
        result_type result;
        internal::object_repository repo;

    public:
        factory(FactoryCallback const& fn, internal::object_repository r = internal::object_repository()) :
            factory_cb(fn),
            parameters(),
            result(),
            repo(r)
        {
        }

        result_type run()
        {
            repo.gather<FactoryCallback>(parameters);
            return call(factory_cb, parameters);
        }
    };

} // namespace lift