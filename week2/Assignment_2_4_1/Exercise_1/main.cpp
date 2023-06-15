// main.cpp
#include "file_reader.h"
#include "printer.h"

int main()
{
    std::string file_name{"lorem_ipsum.txt"};
    // Read the file contents into a vector
    auto content{read_file(file_name)};
    // Function call to print the contents of the vector
    print_file_content(content);

    return 0;
}
