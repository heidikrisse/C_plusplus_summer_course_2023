// unit_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/static_allocator.h"

#include <vector>

// Test the allocation of memory of the StaticAllocator within the defined SIZE limit
TEST_CASE("Allocate memory within SIZE limit")
{
    StaticAllocator<int> allocator;

    int *ptr1 = allocator.allocate(1);
    int *ptr2 = allocator.allocate(1);

    // Check the first allocation is not nullprint (is successfull)
    CHECK(ptr1 != nullptr);
    // Check the second allocation is not nullprint
    CHECK(ptr2 != nullptr);
    // Check that the two allocated addresses are contiguous
    CHECK(ptr2 - ptr1 == 1);
}

// Test trying to allocate memory that would exceed the SIZE limit
TEST_CASE("Overallocate memory beyond SIZE limit")
{
    StaticAllocator<int> allocator;
    // Tries to allocate more memory than SIZE
    int *ptr1 = allocator.allocate(SIZE / sizeof(int) + 1);

    // Check that the allocation fails and returns nullptr
    CHECK(ptr1 == nullptr);
}

// Test the comparison operators of the StaticAllocator
TEST_CASE("Test allocator comparison operators")
{
    StaticAllocator<int> allocator1;
    StaticAllocator<int> allocator2;

    // Allocators of the same type should be equal
    CHECK(allocator1 == allocator2);
}

// Test using StaticAllocator with a vector
TEST_CASE("Test insert values into std::vector using StaticAllocator")
{
    std::vector<int, StaticAllocator<int>> numbers;

    for (int i{1}; i < 11; ++i)
    {
        numbers.push_back(i);
    }
    // 10 values should be added to the vector
    CHECK(numbers.size() == 10);

    // Check that the values added to the vector are correct
    for (int i{0}; i < 10; ++i)
    {
        CHECK(numbers[i] == i + 1);
    }
}
