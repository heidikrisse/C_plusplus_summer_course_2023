// memerror1_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/memerror1.h"

TEST_CASE("Memerror1 - Test large_object construction and destruction")
{
    // Check object storage is initially empty
    CHECK(object_storage.size() == 0);

    {
        large_object a;
        CHECK(object_storage.size() == 1);
        CHECK(object_storage[0].name == "object number 0");

        // Copy constructor
        large_object b = a;
        CHECK(object_storage.size() == 2);
        CHECK(object_storage[1].name == "object number 0"); // copied also the name

        large_object c;
        CHECK(object_storage.size() == 3);
        CHECK(object_storage[2].name == "object number 2");

        CHECK(object_storage.size() == 3);
    }
    // All large_object instances(a, b, and c) go out of scope and are destroyed

    CHECK(object_storage.size() == 0);
}
