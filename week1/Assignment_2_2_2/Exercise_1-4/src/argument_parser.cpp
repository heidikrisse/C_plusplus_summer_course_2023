// argument_parser.cpp
#include "../includes/argument_parser.h"

// Function to define command line options
cxxopts::Options get_options()
{
    // Initialize an Options object with program messages
    cxxopts::Options options("\n--operation valueA valueB", "\nCALCULATOR PROGRAM\n");

    auto option_adder{options.add_options()};

    /* Add options to the Options object.
     *
     * cxxopts library uses "arg" in the help message to indicate that
     * an option requires an argument.
     *
     * The second argument is the help string. The third argument defines
     * the expected type of the option value(s). */
    option_adder("add", "Add two numbers", cxxopts::value<std::vector<double>>());
    option_adder("sub", "Subtract two numbers", cxxopts::value<std::vector<double>>());
    option_adder("mul", "Multiply two numbers", cxxopts::value<std::vector<double>>());
    option_adder("div", "Divide two numbers", cxxopts::value<std::vector<double>>());
    option_adder("enc", "Encrypt a string with Caesar's cipher", cxxopts::value<std::vector<std::string>>());
    option_adder("dec", "Decrypt a string with Caesar's cipher", cxxopts::value<std::vector<std::string>>());
    option_adder("help", "Print usage");

    return options;
}

// Function to parse command line arguments based on the options
cxxopts::ParseResult parse_arguments(int argc, char *argv[], cxxopts::Options &options)
{
    return options.parse(argc, argv);
}
