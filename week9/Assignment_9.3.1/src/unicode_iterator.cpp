// unicode_iterator.cpp
#include "../include/unicode_iterator.h"

#include <stdexcept>

// Constructor initializating UnicodeIterator with a pointer to a character
UnicodeIterator::UnicodeIterator(pointer ptr) : current_(ptr) {}

// Constructor of the UnicodeIterator using std::string::iterator for Exercise 3
UnicodeIterator::UnicodeIterator(std::string::iterator it)
    : current_(&(*it)) {}

// Function to get the number of bytes of a UTF-8 character
unsigned char UnicodeIterator::get_num_bytes(unsigned char byte)
{
    // UTF-8 encoding can be determined by the leading bits in the first byte
    // Leading 0 means a single-byte ASCII character
    if ((byte & 0b10000000) == 0)
    {
        return 1;
    }
    // 110xxxxx means start of a 2-byte character
    else if ((byte & 0b11100000) == 0b11000000)
    {
        return 2;
    }
    // 1110xxxx means start of a 3-byte character
    else if ((byte & 0b11110000) == 0b11100000)
    {
        return 3;
    }
    // 11110xxx means start of a 4-byte character
    else if ((byte & 0b11111000) == 0b11110000)
    {
        return 4;
    }
    // Else the UTF-8 encoding is invalid
    else
    {
        throw std::runtime_error("Invalid UTF-8 start byte encountered");
    }
}

// Function to extract the codepoint from the UTF-8 encoded string
UnicodeIterator::value_type UnicodeIterator::extract_codepoint(pointer ptr)
{
    // Determine the number of bytes for the character
    unsigned char num_bytes{get_num_bytes(*ptr)};
    value_type codepoint{0};
    // Use bit operations to decode the UTF-8 sequence into a codepoint
    switch (num_bytes)
    {
    // Single-byte ASCII character
    case 1:
        return *ptr;
    // 2-byte UTF-8 character
    case 2:
        codepoint = (ptr[0] & 0b00111111) << 6;
        codepoint |= (ptr[1] & 0b00111111);
        break;
    // 3-byte UTF-8 character
    case 3:
        codepoint = (ptr[0] & 0b00001111) << 12;
        codepoint |= (ptr[1] & 0b00111111) << 6;
        codepoint |= (ptr[2] & 0b00111111);
        break;
    // 4-byte UTF-8 character
    case 4:
        codepoint = (ptr[0] & 0b00000111) << 18;
        codepoint |= (ptr[1] & 0b00111111) << 12;
        codepoint |= (ptr[2] & 0b00111111) << 6;
        codepoint |= (ptr[3] & 0b00111111);
        break;
    }
    return codepoint;
}

// Moves the iterator to the next UTF-8 character
UnicodeIterator &UnicodeIterator::operator++()
{
    // Move the pointer by the number of bytes of the current character
    current_ += get_num_bytes(*current_);
    return *this;
}

// Dereference operator
// Gets the Unicode codepoint of the current character
UnicodeIterator::value_type UnicodeIterator::operator*() const
{
    return extract_codepoint(current_);
}

// Equality operator
// Checks if two UnicodeIterators point to the same location
bool UnicodeIterator::operator==(const UnicodeIterator &other) const
{
    return current_ == other.current_;
}

// Inequality operator
// Checks if two UnicodeIterators point to different locations
bool UnicodeIterator::operator!=(const UnicodeIterator &other) const
{
    return !(*this == other);
}
