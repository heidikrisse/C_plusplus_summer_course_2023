// text_file.h
#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include <string>
#include <cstdio> // for FILE*, fopen, fclose, fgetc

class TextFile
{
private:
    // File handle for the C file operations
    FILE *file_handle;

public:
    // Constructor to open a text file with given filename and mode
    TextFile(const char *filename, const char *mode);

    ~TextFile();

    // Function to read the next line of the text file
    std::string read_next_line();

    // Function to print the text file size
    void print_file_size();
};

#endif
