// main.cpp
#include "nlohmann/json.hpp"
#include "include/json_file_handling.h"

#include <iostream>

int main()
{
    read_and_print_json();
    write_json_to_file();

    return 0;
}
