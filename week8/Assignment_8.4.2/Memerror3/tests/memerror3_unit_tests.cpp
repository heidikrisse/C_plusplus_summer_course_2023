// memerror3_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/memerror3.h"

TEST_CASE("Memerror3 - Test cpp_wrapper construction and destruction")
{
    {
        cpp_wrapper wrapper;
        // Here, we are just testing that construction and destruction work without any error
    }
}

TEST_CASE("Memerror3 - Test move constructor and move assignment")
{
    cpp_wrapper original;
    original.values().random = 99;

    // Test move constructor
    cpp_wrapper moved = std::move(original);
    CHECK(moved.values().random == 99);

    cpp_wrapper another;
    another.values().random = 50;

    // Test move assignment
    moved = std::move(another);
    CHECK(moved.values().random == 50);
}

TEST_CASE("Memerror3 - Test do_stuff method")
{
    cpp_wrapper wrapper;
    // Since do_stuff() doesn't have a return value and only prints, this is just to ensure
    // it doesn't cause any crashes/errors
    wrapper.do_stuff();
}

TEST_CASE("Memerror3 - Test build_wrapper function")
{
    auto built{build_wrapper()};
    CHECK(built.values().random == 42);
}
