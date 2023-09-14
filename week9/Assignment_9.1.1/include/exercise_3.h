#ifndef EXERCISE_3_H
#define EXERCISE_3_H

#include <unordered_map>
#include <string>
#include "exercise_2.h"

using variable_map_t = std::unordered_map<std::string, int>;

// Function to set two variables in variable_map
void set_variable(variable_map_t &variable_map);
// Function to return the variable value
int get_variable_value(const variable_map_t &variable_map, const std::string &variable_name);

// Function to calculate operation with variables
void calculate_operation_with_variables(const calculator_map_t &calculator_functions, const variable_map_t &variable_map);

#endif
