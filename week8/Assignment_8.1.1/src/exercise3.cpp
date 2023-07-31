// exercise3.cpp
#include "../include/exercise3.h"

void check_contiguous_memory_different_containers()
{
    std::vector<int> vec(1000, 0);
    std::list<int> lst(1000, 0);
    std::array<int, 1000> arr{};
    std::deque<int> deq(1000, 0);

    std::cout << std::boolalpha; // To get alphabets true or false instead of 1 or 0
    std::cout << "For std::vector<int>: Are elements contiguous in memory? " << are_elements_contiguous(vec) << '\n';
    std::cout << "For std::list<int>: Are elements contiguous in memory? " << are_elements_contiguous(lst) << '\n';
    std::cout << "For std::array<int, 1000>: Are elements contiguous in memory? " << are_elements_contiguous(arr) << '\n';
    std::cout << "For std::deque<int>: Are elements contiguous in memory? " << are_elements_contiguous(deq) << '\n';
}
