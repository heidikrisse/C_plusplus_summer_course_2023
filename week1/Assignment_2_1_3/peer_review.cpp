// peer_review.cpp

#include "peer_review.hpp"
#include <algorithm>
#include <random>
#include <iostream>

std::vector<std::string> get_student_names()
{
    std::vector<std::string> students{};
    std::string name{};

    std::cout << "Enter the number of students: ";
    int num_students{};
    std::cin >> num_students;

    for (int i{0}; i < num_students; ++i)
    {
        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::cin >> name;
        students.push_back(name);
    }

    return students;
}

std::map<std::string, std::string> create_peer_review_list(const std::vector<std::string> &students)
{
    // Copy the original vector of students
    std::vector<std::string> shuffled_students{students};

    // Shuffle the copied list
    std::random_device rd{};
    std::mt19937 g(rd());
    std::shuffle(shuffled_students.begin(), shuffled_students.end(), g);

    // Creating the review list
    std::map<std::string, std::string> review_list{};

    // Assigning each student to review another student's work
    for (size_t i{0}; i < students.size(); ++i)
    {
        std::string reviewer{students[i]};
        std::string reviewee{shuffled_students[(i + 1) % shuffled_students.size()]};
        review_list[reviewer] = reviewee;
    }

    return review_list;
}

void print_review_list(const std::map<std::string, std::string> &review_list)
{
    std::cout << "\nPeer review list:\n\n";
    for (const auto &pair : review_list)
    {
        std::cout << "Student " << pair.first << " will review student " << pair.second << ".\n";
    }
}
