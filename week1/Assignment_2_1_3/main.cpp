/* main.cpp
 *
 * This program asks the user for the names of the students and creates a peer * review list
 */

#include "peer_review.hpp"
#include <iostream>

int main()
{
    // Ask user for the names of the students
    std::vector<std::string> students{get_student_names()};

    // Create the review list
    std::map<std::string, std::string> review_list{create_peer_review_list(students)};

    // Print the review list
    print_review_list(review_list);

    return 0;
}
