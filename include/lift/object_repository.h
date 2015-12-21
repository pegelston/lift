
#pragma once

#include <map>
#include <memory>
#include "object.h"

namespace lift {

    class object_repository
    {
    public:
        object_repository()
        {
        }

        template <typename... Args>
        void gather(Args&&... args)
        {

        }

        template <typename T>
        void stash(T&& t)
        {
            objects.insert(std::make_pair(typeid(decltype(T)).name(), t));
        }

    private:
        std::map<std::string, std::shared_ptr<lift::object>> objects;
    };

} // namespace lift