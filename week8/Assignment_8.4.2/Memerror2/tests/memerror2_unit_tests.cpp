// memerror2_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/memerror2.h"

TEST_CASE("Memerror2 - flawed_array<int>")
{
    flawed_array<int, 5> int_array;

    // Assign values
    for (std::size_t i{0}; i < int_array.size(); ++i)
    {
        int_array[i] = i;
    }

    // Check values
    for (std::size_t i{0}; i < int_array.size(); ++i)
    {
        CHECK(int_array[i] == i);
    }

    // Check copy
    auto int_array_copy{int_array};
    for (std::size_t i{0}; i < int_array_copy.size(); ++i)
    {
        CHECK(int_array_copy[i] == i);
    }
}

TEST_CASE("Memerror2 - flawed_array<std::string>")
{
    flawed_array<std::string, 5> string_array;

    // Assign values
    for (std::size_t i{0}; i < string_array.size(); ++i)
    {
        string_array[i] = "Element " + std::to_string(i);
    }

    // Check values
    for (std::size_t i{0}; i < string_array.size(); ++i)
    {
        CHECK(string_array[i] == ("Element " + std::to_string(i)));
    }

    // Check copy
    auto string_array_copy = string_array;
    for (std::size_t i{0}; i < string_array_copy.size(); ++i)
    {
        CHECK(string_array_copy[i] == ("Element " + std::to_string(i)));
    }
}
