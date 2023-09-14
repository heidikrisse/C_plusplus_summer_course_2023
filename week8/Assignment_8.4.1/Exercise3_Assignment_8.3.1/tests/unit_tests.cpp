// unit_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/heap_array.h"

// --- Exercise 1: ---

TEST_CASE("Default Constructor - Exercise 1")
{
    HeapArray<int> array1;
    CHECK(array1.empty());
    CHECK(array1.size() == 0);
}

TEST_CASE("Constructor with argument(s) - Exercise 1")
{
    HeapArray<int> array1(3);
    CHECK_FALSE(array1.empty());
    CHECK(array1.size() == 3);
}

TEST_CASE("Iterators and storage - Exercise 1")
{
    HeapArray<int> int_array{3};
    int sum{0};
    for (auto val : int_array)
    {
        sum += val;
    }
    CHECK(sum == 0); // Check that default initialized values are 0 for integers

    HeapArray<int>::iterator begin = int_array.begin();
    HeapArray<int>::iterator end = int_array.end();
    CHECK((end - begin) == 3);
}

// --- Exercise 2: ---

TEST_CASE("Copy Constructor and Assignment Operator - Exercise 2")
{
    HeapArray<int> array1(3);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;

    HeapArray<int> copy_array = array1;
    CHECK(copy_array[0] == 1);
    CHECK(copy_array[1] == 2);
    CHECK(copy_array[2] == 3);
}

TEST_CASE("Move Constructor and Assignment Operator - Exercise 2")
{
    HeapArray<int> array1(3);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;

    HeapArray<int> move_array = std::move(array1);
    CHECK(move_array[0] == 1);
    CHECK(move_array[1] == 2);
    CHECK(move_array[2] == 3);
}

// --- Exercise 3:  ---

TEST_CASE("Element Access - Exercise 3")
{
    HeapArray<int> int_array{3};
    for (int i{0}; i < 3; ++i)
    {
        int_array[i] = i;
    }

    CHECK(int_array[2] == 2);
    CHECK(int_array.at(2) == 2);

    CHECK_THROWS_AS(int_array.at(4), std::out_of_range); // should throw the error and this test should fail - all the others should pass
}

// --- Exercise 4: ---

TEST_CASE("Swap two arrays - Exercise 4")
{
    HeapArray<int> array1(2);
    array1[0] = 1;
    array1[1] = 2;

    HeapArray<int> array2(3);
    array2[0] = 3;
    array2[1] = 4;
    array2[2] = 5;

    array1.swap(array2);

    CHECK(array1.size() == 3);
    CHECK(array1[0] == 3);
    CHECK(array1[1] == 4);
    CHECK(array1[2] == 5);

    CHECK(array2.size() == 2);
    CHECK(array2[0] == 1);
    CHECK(array2[1] == 2);
}

// --- Exercise 5: ---

TEST_CASE("Rest of the Container requirements - Exercise 5")
{
    // All subcases can access the array
    HeapArray<int> int_array{3};

    // Test begin() and end()
    SUBCASE("begin() and end()")
    {
        CHECK(int_array.begin() != int_array.end());
        CHECK(std::distance(int_array.begin(), int_array.end()) == 3);
    }

    // Test size(), empty(), and clear()
    SUBCASE("size(), empty(), and clear()")
    {
        CHECK(int_array.size() == 3);
        CHECK_FALSE(int_array.empty());

        int_array.clear();
        CHECK(int_array.size() == 0);
        CHECK(int_array.empty());
    }

    // Test max_size()
    SUBCASE("max_size()")
    {
        CHECK(int_array.max_size() == std::numeric_limits<std::size_t>::max());
    }

    // Test equality operator (==) and inequality operator (!=)
    SUBCASE("Equality operator (==) and inequality operator (!=)")
    {
        HeapArray<int> array2{3};
        for (int i{0}; i < 3; ++i)
        {
            array2[i] = i + 1;
        }

        CHECK(array2 == array2); // Same array is equal to itself
        CHECK_FALSE(int_array == array2);
        CHECK(int_array != array2); // Inequal

        HeapArray<int> array3{3};
        for (int i{0}; i < 3; ++i)
        {
            array3[i] = i + 1;
        }

        CHECK(array2 == array3); // array2 and array3 are identical arrays: equal
        CHECK_FALSE(int_array == array3);
        CHECK(int_array != array3);

        array2[0] = 5;
        CHECK_FALSE(array2 == array3); // inequal
        CHECK(array2 != array3);
    }
}
