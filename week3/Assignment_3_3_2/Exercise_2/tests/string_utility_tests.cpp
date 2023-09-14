#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/string_utils.h"

TEST_CASE("Reverse string test")
{
    CHECK(reverse_string("hello") == "olleh");
    CHECK(reverse_string("mom") == "mom");
    CHECK(reverse_string("") == "");
}

TEST_CASE("Uppercase test")
{
    CHECK(to_uppercase("hello") == "HELLO");
    CHECK(to_uppercase("MOM") == "MOM");
    CHECK(to_uppercase("Mom") == "MOM");
}

TEST_CASE("Lowercase test")
{
    CHECK(to_lowercase("hello") == "hello");
    CHECK(to_lowercase("HELLO") == "hello");
    CHECK(to_lowercase("Hello") == "hello");
}

TEST_CASE("Palindrome test")
{
    CHECK(is_palindrome("hello") == false);
    CHECK(is_palindrome("mom") == true);
    CHECK(is_palindrome("ABBA") == true);
    CHECK(is_palindrome("SuMMer") == false);
}
