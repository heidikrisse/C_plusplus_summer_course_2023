// user_ui.h
#ifndef USER_UI_H
#define USER_UI_H

#include <string>

// Prompt user for a positive integer input
std::size_t get_positive_input(const std::string &prompt);

// Prompt user for a general integer input
int get_input(const std::string &prompt);

#endif
