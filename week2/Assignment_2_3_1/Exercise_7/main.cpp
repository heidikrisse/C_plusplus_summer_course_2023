/* main.cpp
 *
 * A program to create a vector of pairs with repeating first elements.
 * After sorting, it checks if the pairs with equal first elements maintain their relative order.
 **/
#include "get_vector_input.h"
#include "stable_sort_vector.h"
#include "print_pairs_vector.h"
#include "check_relative_order.h"

int main()
{
    std::vector<std::pair<int, std::string>> vec{get_pairs_vector_from_user()};
    stable_sort_vector(vec);
    print_pairs_vector(vec);
    check_relative_order(vec);

    return 0;
}
