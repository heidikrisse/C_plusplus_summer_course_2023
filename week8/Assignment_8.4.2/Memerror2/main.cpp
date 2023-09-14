// main.cpp
#include "include/memerror2.h"

int main()
{
    // Original int array:
    /*
    flawed_array<int, 5> int_array;

    for (std::size_t i = 0; i < int_array.size(); ++i)
    {
        int_array[i] = i;
    }

    for (auto &elem : int_array)
    {
        std::cout << elem << "\n";
    }

    auto int_array_copy = int_array;

    for (auto &elem : int_array_copy)
    {
        std::cout << elem << "\n";
    }
    */

    // Works like a charm so far.  Where's the error?

    // String array:

    flawed_array<std::string, 5> string_array;

    for (std::size_t i = 0; i < string_array.size(); ++i)
    {
        string_array[i] = "Element " + std::to_string(i);
    }

    for (const auto &elem : string_array)
    {
        std::cout << elem << '\n';
    }

    auto string_array_copy = string_array;

    for (const auto &elem : string_array_copy)
    {
        std::cout << elem << '\n';
    }
}
