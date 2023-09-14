// unit_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/unicode_iterator.h"
#include "../include/string_adapter.h"

// Exercise 3:
TEST_CASE("Convert std::string::iterator to UnicodeIterator")
{
    std::string test_string{"Today"};
    UnicodeIterator it(test_string.begin());
    CHECK(*it == test_string[0]);
}

TEST_CASE("Valid UTF-8 sequence handling")
{
    std::string valid_string{"Today is a ☀ day!"};
    StringAdapter adapter(valid_string);
    bool exception_thrown{false};
    try
    {
        for (auto codepoint : adapter)
        {
            // this should not throw any exception
            std::cout << static_cast<uint32_t>(codepoint) << ' ';
        }
    }
    catch (const std::runtime_error &)
    {
        exception_thrown = true;
    }
    CHECK(exception_thrown == false);
}

TEST_CASE("Invalid UTF-8 sequence handling")
{
    std::string invalid_string{"Invalid UTF\x80"};
    StringAdapter adapter(invalid_string);
    bool exception_thrown{false};
    try
    {
        for (auto codepoint : adapter)
        {
            // To avoid the unused variable warning
            (void)codepoint;
        }
    }
    catch (const std::runtime_error &)
    {
        exception_thrown = true;
    }
    CHECK(exception_thrown == true);
}

// Exercise 4:
TEST_CASE("Traverse individual Unicode codepoints of a UTF-8 string")
{
    std::string test_str{"Today is a ☀ day!"};
    StringAdapter adapter(test_str);

    // Count the number of codepoints in a string
    size_t count{0};
    for (auto codepoint : adapter)
    {
        ++count;
    }
    CHECK(count == 17); // 17 characters
}

// Exercise 5:
TEST_CASE("Dereference UnicodeIterator to get Unicode codepoint value")
{
    std::string test_str{"a"};
    StringAdapter adapter(test_str);

    auto it{adapter.begin()};
    // Unicode codepoint for 'a' should be 0x61
    CHECK(static_cast<uint32_t>(*it) == 0x61);
    // or unicode codepoint for 'a' in decimal should be 97
    CHECK(static_cast<uint32_t>(*it) == 97);
}
