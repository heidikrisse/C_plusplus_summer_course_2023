/* main.cpp
 *
 * A program to create a vector of integers, find the top 5 elements
 * using std::partial_sort and print the top 5 elements in descending order.
 * The vector should have at least 20 elements.
 **/
#include "get_vector_input.h"
#include "partial_sort_vector.h"
#include "print_vector.h"

int main()
{
    std::vector<int> vec{get_int_vector_from_user()};
    partial_sort_vector(vec);
    print_int_vector(vec);

    return 0;
}
