// basic_math_unit_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/basic_math_functions.h"

TEST_CASE("Testing addition")
{
    CHECK(add(2.0, 2.0) == doctest::Approx(4.0));
    CHECK(add(-2.0, -2.0) == doctest::Approx(-4.0));
}

TEST_CASE("Testing subtraction")
{
    CHECK(subtract(4.0, 2.0) == doctest::Approx(2.0));
    CHECK(subtract(-2.0, -2.0) == doctest::Approx(0.0));
}

TEST_CASE("Testing multiplication")
{
    CHECK(multiply(2.0, 2.0) == doctest::Approx(4.0));
    CHECK(multiply(-2.0, 4.0) == doctest::Approx(-8.0));
}

TEST_CASE("Testing division")
{
    CHECK(divide(4.0, 2.0) == doctest::Approx(2.0));
    CHECK_THROWS_AS(divide(2.0, 0.0), std::invalid_argument);
}
