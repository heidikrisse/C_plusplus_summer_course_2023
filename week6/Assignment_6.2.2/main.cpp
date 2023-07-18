// main.cpp
#include "text_file.h"

#include <iostream>  // for std:.cout
#include <stdexcept> // for std::runtime_error

int main()
{
    try
    {
        const char *filename{"text_file.txt"};
        // Open the text file with "read"-mode
        TextFile file(filename, "r");

        std::string line;
        while (!(line = file.read_next_line()).empty())
        { // Read the text file line by line
            std::cout << line << "\n";
        }
        // Function to print the text file size
        file.print_file_size();
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Exception caught: " << e.what();
    }

    return 0;
}
