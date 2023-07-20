// text_file.h
#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include <string>
#include <cstdio> // for FILE*, fopen, fclose, fgetc
#include <string_view>
#include "tagged_union.h"

class TextFile
{
private:
    FILE *file_handle;

public:
    TextFile(const char *filename, const char *mode);
    ~TextFile();

    std::string read_next_line();
    void print_file_size();

    // EXERCISE 2:
    static TaggedUnion create_object_from_string(const std::string &str);
};

// Function to check if the string is a float
bool is_float(std::string_view input);

// Function to check if the string is an integer
bool is_int(std::string_view input);

#endif
