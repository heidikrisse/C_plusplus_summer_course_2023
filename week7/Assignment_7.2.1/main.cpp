// main.cpp
#include "include/exercise1.h"
#include "include/exercise2.h"
#include "include/exercise3.h"
#include "include/exercise4.h"
#include "include/exercise5.h"

#include <vector>
#include <list>
#include <iostream>

int main()
{
    const int value1{1};
    const int value2{2};
    const int value3{3};
    const int value4{4};

    // Testing Exercise 1a
    std::cout << "Exercise 1a:\n";
    print_first_and_call_rest(value1, value2, value3);
    std::cout << '\n';

    // Testing Exercise 1b
    std::cout << "Exercise 1b:\n";
    print_with_if_constexpr(value1, value2, value3);
    std::cout << '\n';

    // Testing Exercise 2
    std::cout << "Exercise 2:\n";
    std::cout << "Sum of arguments (" << value1 << " + " << value2 << " + " << value3 << "): " << sum_of_arguments(value1, value2, value3) << '\n'; // Should print 6
    std::cout << '\n';

    // Testing Exercise 3
    std::cout << "Exercise 3:\n";
    std::cout << "Are all types (int, int, int) same? " << std::boolalpha << are_all_same<int, int, int>() << '\n'; // Should print true
    std::cout << '\n';

    std::cout << "Are all types (int, double, int) same? " << std::boolalpha << are_all_same<int, double, int>() << '\n'; // Should print false
    std::cout << '\n';

    std::cout << "Are all types (int, float) same? " << std::boolalpha << are_all_same<int, float>() << '\n'; // Should print false
    std::cout << '\n';

    // Testing Exercise 4
    std::cout << "Exercise 4:\n";
    size_t arg_count{count_args(value1, value2, value3)};
    std::cout << "Product of arguments * nbr of arguments (("
              << value1 << "*" << value2 << "*" << value3 << ") * " << arg_count << "): " << product_of_args_times_count(value1, value2, value3) << '\n';
    std::cout << '\n';

    // Testing Exercise 5
    std::cout << "Exercise 5:\n";
    std::vector<int> vector1 = {value1, value2};
    std::list<int> list1 = {value3, value4};
    auto concatenated{concatenate_containers<std::vector<int>>(vector1, list1)};
    for (auto &elem : concatenated)
    {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    return 0;
}
