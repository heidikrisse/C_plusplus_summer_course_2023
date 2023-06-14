/* main.cpp
 *
 * A program to reate a vector of floating-point numbers and sort
 * it. Experiment with different sizes of vectors and number ranges.
 **/
#include "get_vector_input.h"
#include "sort_float_vector.h"
#include "print_vector.h"

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<float> vec{get_vector_from_user()};

    sort_float_vector(vec);

    print_vector(vec);

    return 0;
}
