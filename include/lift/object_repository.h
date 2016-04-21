
#pragma once

#include <map>
#include <tuple>
#include "index_tuple.h"
#include "object.h"
#include "static_for.h"

namespace lift {
    namespace internal {

        class object_repository
        {
        private:
            template <typename T>
            struct gatherer :
                public gatherer <decltype(&T::operator())>
            {
                // For generic types, directly use the result of the signature of its 'operator()'
            };

            // we specialize for pointers to member function
            template <typename ClassType, typename ReturnType, typename... Args>
            struct gatherer <ReturnType(ClassType::*)(Args...) const>
            {
                template <typename F, typename Tuple>
                static void gather(F const& f, Tuple&& t)
                {
                    // Create a parameter pack of indices and use that to expand the
                    // tuple into a parameter pack to be passed to the function.
                    return populate(f, t, typename make_indices<sizeof...(Args)>::type());
                }

                template <typename F, typename Tuple, size_t... Indices>
                static void populate(F const& f, Tuple&& t, index_tuple<Indices...>)
                {
                    // Call the setter function for each tuple parameter reference.
                    meta::static_for(f, std::get<Indices>(std::forward<Tuple>(t))...);
                }
            };

            struct set_parameter
            {
                std::map<std::string, std::string> const& objects;

                set_parameter(std::map<std::string, std::string> const& os) :
                    objects(os)
                {
                }

                template <typename T>
                void operator()(T& parameter) const
                {
                    parameter = objects.find(typeid(T).name())->second;
                }
            };

        public:
            object_repository()
            {
            }

            template <typename F, typename Tuple>
            void gather(Tuple&& t)
            {
                gatherer<F>::gather(set_parameter(objects), t);
            }

            template <typename T>
            void stash(T&& t)
            {
                objects.insert(std::make_pair(typeid(T).name(), t));
            }

        private:
            std::map<std::string, std::string> objects;
        };

    } // namespace internal
} // namespace lift