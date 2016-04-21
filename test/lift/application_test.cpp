
#include <iostream>
#include <string>
#include "lift/application.h"
#include "lift/object_repository.h"

using namespace lift;

void test_app()
{
    // setting up an object repo for testing purposes.
    internal::object_repository repo;
    repo.stash(std::string("Hello, object repository!"));

    application().create_factory(
        [=](std::string value) -> bool
        {
            std::cout << value << std::endl;

            return true;
        }, repo).run();
}