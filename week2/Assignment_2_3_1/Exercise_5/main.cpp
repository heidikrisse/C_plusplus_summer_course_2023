/* main.cpp
 *
 * A program to create a vector of pairs where each pair contains a string
 * and an integer (like a name and an age) and sort the vector based on
 * the integer (age)
 **/
#include "get_vector_input.h"
#include "sort_pairs_vector.h"
#include "print_pairs_vector.h"

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::pair<std::string, int>> vec{get_pairs_vector_from_user()};
    sort_pairs_vector(vec);
    print_pairs_vector(vec);

    return 0;
}
