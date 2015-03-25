
#include <functional>
#include <tuple>

//
// This class provides the ability to do a static compile time iteration
// over compile time deducable variables.
//

struct static_for
{
public:
    template <typename Lambda, typename Arg, typename... Args>
    static void call(Lambda const& f, Arg&& arg, Args&&... args) // recursive variadic function
    {
        f(std::forward<Arg>(arg));
        call(f, std::forward<Args>(args)...);
    }

    // terminate the recursion
    template <typename Lambda>
    static void call(Lambda const&) {}
};