// unicode_iterator.h
#ifndef UNICODE_ITERATOR_H
#define UNICODE_ITERATOR_H

#include <string>

// Exercise 3:
class UnicodeIterator
{
public:
    using pointer = std::string::pointer;
    using difference_type = std::ptrdiff_t;
    // Exercise 4: Using char32_t for Unicode codepoints
    using value_type = char32_t;
    using reference = value_type &;
    using iterator_category = std::forward_iterator_tag;

    // Constructor taking a pointer
    explicit UnicodeIterator(pointer ptr);

    // Constructor from std::string::iterator
    UnicodeIterator(std::string::iterator it);

    // Increment operator
    UnicodeIterator &operator++();

    // Exercise 5:
    // Dereference operator to read the entire codepoint
    value_type operator*() const;

    // Equality and inequality operators
    bool operator==(const UnicodeIterator &other) const;
    bool operator!=(const UnicodeIterator &other) const;

private:
    pointer current_;

    // Helper functions:
    static unsigned char get_num_bytes(unsigned char byte);
    static value_type extract_codepoint(pointer ptr);
};

#endif
