/* main.cpp
 *
 * A program to create a vector of strings and sort them in
 * lexicographical order and based on the string length.
 **/
#include "get_vector_input.h"
#include "sort_string_vector.h"
#include "print_vector.h"

int main()
{
    std::vector<std::string> vec{get_string_vector_from_user()};
    sort_string_vector(vec);
    print_string_vector(vec);

    return 0;
}
