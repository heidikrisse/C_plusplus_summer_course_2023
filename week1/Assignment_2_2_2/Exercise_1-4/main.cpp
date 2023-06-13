// main.cpp
#include "includes/argument_parser.h"
#include "includes/operation_executor.h"

int main(int argc, char *argv[])
{
    // Call get_options() to configure command line options and store the result
    cxxopts::Options options{get_options()};
    // Parse the command line arguments using options
    auto result{parse_arguments(argc, argv, options)};
    // Execute the operation according to the parsed command line arguments
    execute_operation(result);

    return 0;
}
