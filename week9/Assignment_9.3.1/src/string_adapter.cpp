// string_adapter.cpp
#include "../include/string_adapter.h"

// Exercise 7:

// Constructor
// Initializes the internal string reference
StringAdapter::StringAdapter(const std::string &str) : str_(str) {}

// Begin iterator function
StringAdapter::iterator StringAdapter::begin() const
{
    return iterator(const_cast<char *>(str_.data()));
}

// End iterator function
StringAdapter::iterator StringAdapter::end() const
{
    return iterator(const_cast<char *>(str_.data() + str_.size()));
}

// Function to count the number of Unicode codepoints in the string
size_t StringAdapter::size() const
{
    size_t count{0};
    for (auto it = begin(); it != end(); ++it)
    {
        ++count;
    }
    return count;
}
