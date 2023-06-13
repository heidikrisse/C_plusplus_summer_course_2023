/* argument_parser.h
 *
 * Handles command line argument parsing
 */
#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include "../external/cxxopts/include/cxxopts.hpp"
#include <string>

// Function to define command line options
cxxopts::Options get_options();
// Function to parse command line arguments
cxxopts::ParseResult parse_arguments(int argc, char *argv[], cxxopts::Options &options);

#endif // ARGUMENT_PARSER_H
