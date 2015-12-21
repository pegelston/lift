
#pragma once

namespace lift {
    namespace meta {

        //
        // static_for provides the ability to do a static compile time iteration
        // over compile time deducable variables.
        //

        template <typename Lambda, typename Arg, typename... Args>
        static void static_for(Lambda const& f, Arg&& arg, Args&&... args) // recursive variadic function
        {
            f(std::forward<Arg>(arg));
            static_for(f, std::forward<Args>(args)...);
        }

        // terminate the recursion
        template <typename Lambda>
        static void static_for(Lambda const&) {}

    } // namespace meta
} // namespace lift