// text_file.cpp
#include "text_file.h"

#include <iostream>
#include <stdexcept> // for std::runtime_error
#include <charconv>

TextFile::TextFile(const char *filename, const char *mode)
{
    std::string data_folder_path{"../data/"};
    std::string file_path{data_folder_path + filename};
    file_handle = fopen(file_path.c_str(), mode);
    if (!file_handle)
    {
        file_handle = fopen(file_path.c_str(), "w");
        if (!file_handle)
        {
            throw std::runtime_error("Failed to create the text file.\n");
        }
    }
}

TextFile::~TextFile()
{
    if (file_handle)
    {
        std::fclose(file_handle);
    }
}

std::string TextFile::read_next_line()
{
    std::string line{};
    int symbol{};

    while ((symbol = std::fgetc(file_handle)) != EOF && symbol != '\n')
    {
        line += static_cast<char>(symbol);
    }

    return line;
}

void TextFile::print_file_size()
{
    long current_position{std::ftell(file_handle)};
    std::fseek(file_handle, 0, SEEK_END);
    long size{std::ftell(file_handle)};
    std::fseek(file_handle, current_position, SEEK_SET);
    std::cout << "Text file size: " << size << " bytes\n";
}

// EXERCISE 2:
TaggedUnion TextFile::create_object_from_string(const std::string &str)
{
    TaggedUnion tagged_union;

    if (is_int(str))
    {
        tagged_union.set_robot(std::stoi(str));
    }
    else if (is_float(str))
    {
        tagged_union.set_alien(std::stof(str));
    }
    else if (!str.empty())
    {
        tagged_union.set_person(str[0]);
    }

    return tagged_union;
}

bool is_float(std::string_view input)
{
    double val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

bool is_int(std::string_view input)
{
    int val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}
