// unit_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/exercise2.h"

TEST_CASE("DebugClass Constructor and Destructor Counter")
{
    {
        // Default constructor
        DebugClass<false> obj1;
        // Copy constructor
        DebugClass<false> obj2 = obj1;
        // Move constructor
        DebugClass<false> obj3 = std::move(obj2);
    } // All (default, copy and move) constructors are destroyed

    // Check the counters:
    CHECK(DebugClass<false>::default_constructor_count == 1);
    CHECK(DebugClass<false>::copy_constructor_count == 1);
    CHECK(DebugClass<false>::move_constructor_count == 1);
    // All 3 objects should be destroyed
    CHECK(DebugClass<false>::destructor_count == 3);
}
