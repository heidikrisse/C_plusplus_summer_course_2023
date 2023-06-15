// command_handler.cpp
#include "../include/command_handler.h"
#include "../include/printer.h"

#include <iostream>
#include <cstring>

/* Function to handle command-line arguments and execute the
 * corresponding actions.
 * -  expects the command-line arguments count (argc) and an array of
 *    the command-line arguments (argv) */
void handle_arguments(int argc, char *argv[])
{
    // If no command-line arguments are provided
    if (argc < 2)
    {
        std::cout << "No arguments provided.\n\n";
        print_usage_instructions();

        return;
    }

    // Convert the first command-line argument to a string
    std::string option(argv[1]);

    // If no option is provided, call the function to print the file contents
    if (argc == 2)
    {
        print_file_content(argv[1]);
    }
    /* If a user inputs '-l' or '--lines', call the function to print
     * the number of lines in the file */
    else if (argc == 3 && (option == "-l" || option == "--lines"))
    {
        print_line_count(argv[2]);
    }
    /* If a user inputs '-w' or '--words', call the function to print
     * the number of words in the file */
    else if (argc == 3 && (option == "-w" || option == "--words"))
    {
        print_word_count(argv[2]);
    }
    /* If a user inputs '-c' or '--chars', call the function to print
     * the number of characters in the file */
    else if (argc == 3 && (option == "-c" || option == "--chars"))
    {
        print_char_count(argv[2]);
    }
    /* If a user inputs '-s' or '--size', call the function to print
     * the size of all text files in the directory */
    else if (argc == 3 && (option == "-s" || option == "--size"))
    {
        print_directory_size(argv[2]);
    }
    else
    {
        std::cout << "Invalid arguments.\n\n";
        print_usage_instructions();

        return;
    }
}
