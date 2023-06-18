/* peer_review.hpp

 * Header file to declare the functions for getting student names and creating
 * a peer review list
 */

#ifndef PEER_REVIEW_H
#define PEER_REVIEW_H

#include <vector>
#include <map>
#include <string>

// Function to get the student names
std::vector<std::string> get_student_names();
// Function to create a peer review list
std::map<std::string, std::string> create_peer_review_list(const std::vector<std::string> &students);
// To print the peer review list
void print_review_list(const std::map<std::string, std::string> &review_list);

#endif
