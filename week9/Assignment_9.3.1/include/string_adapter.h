// string_adapter.h
#ifndef STRING_ADAPTER_H
#define STRING_ADAPTER_H

#include "unicode_iterator.h"
#include <string>

// Exercise 7:
class StringAdapter
{
public:
    // Type aliases
    using iterator = UnicodeIterator;
    using const_iterator = const UnicodeIterator;

    // Constructor that initializes with a reference to a std::string
    explicit StringAdapter(const std::string &str);

    // Returns an iterator pointing to the beginning of the string
    iterator begin() const;
    // Returns an iterator pointing to the end of the string
    iterator end() const;

    // Function to count the number of Unicode codepoints in the string
    size_t size() const;

private:
    // Reference to the original string
    const std::string &str_;
};

#endif
