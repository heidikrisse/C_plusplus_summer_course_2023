#ifndef EXERCISE_2_H
#define EXERCISE_2_H

#include <unordered_map>
#include <functional>

using calculator_map_t = std::unordered_map<char, std::function<int(int, int)>>;

// Function to returns an unordered_map of char and function pairs
calculator_map_t get_calculator_functions();
void perform_operation(const calculator_map_t &calculator_functions);

#endif
