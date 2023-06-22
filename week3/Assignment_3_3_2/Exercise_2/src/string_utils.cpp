#include "../include/string_utils.h"
#include <algorithm>

std::string reverse_string(const std::string &str)
{
    return std::string(str.rbegin(), str.rend());
}

std::string to_uppercase(const std::string &str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string to_lowercase(const std::string &str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

bool is_palindrome(const std::string &str)
{
    return std::equal(str.begin(), str.end(), str.rbegin());
}
