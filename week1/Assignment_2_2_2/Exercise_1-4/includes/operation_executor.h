/* operation_executor.h
 *
 * Executes the calculation operation according to the parsed command line
 * arguments.
 */
#ifndef OPERATION_EXECUTOR_H
#define OPERATION_EXECUTOR_H

#include "../includes/calculator_utils.h"
#include "../external/cxxopts/include/cxxopts.hpp"

#include <string>
#include <vector>

// Function to execute an operation based on parsed command line arguments
void execute_operation(cxxopts::ParseResult &result);

#endif // OPERATION_EXECUTOR_H
