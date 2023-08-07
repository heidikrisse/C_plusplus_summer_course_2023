#ifndef EXERCISE_1_H
#define EXERCISE_1_H

#include <functional>
#include <vector>

// Define a type for a function that takes no arguments and returns void
using void_func_t = std::function<void()>;

void function_1();
void function_2();

std::vector<void_func_t> get_functions();
void call_user_function(const std::vector<void_func_t> &functions);

#endif
