// main.cpp
#include "include/exercise_1.h"
#include "include/exercise_2.h"
#include "include/exercise_3.h"
#include "include/exercise_4.h"
#include "include/exercise_5.h"

#include <iostream>

int main()
{
    // Exercise 1:
    std::cout << "----- Exercise 1: -----\n\n";
    int value{5}; // 0b101
    std::cout << "Binary representation of " << value << ": ";
    print_bits(value);

    int bit_position{2};
    // 3. bit from the right (because the calculation starts with 0) in value 5 (binary value 0b101) is set so the function should return true
    if (is_nth_bit_set(value, bit_position))
    {
        std::cout << "The " << bit_position << "th bit is set in a value " << value << ".\n";
    }
    else
    {
        std::cout << "The " << bit_position << "th bit is not set in " << value << ".\n";
    }

    // Exercise 2:
    std::cout << "\n----- Exercise 2: -----\n\n";

    //  8-bit: each 8-bit byte is a 2-digit hex number
    std::cout << "Original value in hexadecimals: 12\n";
    uint8_t original_8bit_value{0x12};
    std::cout << "Original value in decimal: " << original_8bit_value << '\n';
    std::cout << "Original value in bits: ";
    print_bits(original_8bit_value);
    // Swap byte order of the given value
    uint8_t swapped_8bit_value{swap_byte_order(original_8bit_value)};
    std::cout << "Swapped value in decimal: " << swapped_8bit_value << '\n';
    std::cout << "Swapped value in bits: ";
    print_bits(swapped_8bit_value);
    std::cout << '\n';

    //  16-bit: each 16-bit byte is a 4-digit hex number
    std::cout << "Original value in hexadecimals: 1234\n";
    uint16_t original_16bit_value{0x1234};
    std::cout << "Original value in decimal: " << original_16bit_value << '\n';
    std::cout << "Original value in bits: ";
    print_bits(original_16bit_value);
    // Swap byte order of the given value
    uint16_t swapped_16bit_value{swap_byte_order(original_16bit_value)};
    std::cout << "Swapped value in decimal: " << swapped_16bit_value << '\n';
    std::cout << "Swapped value in bits: ";
    print_bits(swapped_16bit_value);
    std::cout << '\n';

    // 32-bit: the 32-bit offset at the start is an 8-digit hex number
    std::cout << "Original value in hexadecimals: 12345678\n";
    uint32_t original_32bit_value{0x12345678};
    // Should be: 305419896:
    // 0x12345678
    // = (8 * 16^0) + (7 * 16^1) + (6 * 16^2) + (5 * 16^3) + (4 * 16^4) + (3 * 16^5) + (2 * 16^6) + (1 * 16^7)
    // = 8 + 112 + 1536 + 20480 + 262144 + 3145728 + 33554432 + 268435456
    // = 305419896
    std::cout << "Original value in decimal: " << original_32bit_value << "\n";
    std::cout << "Original value in bits: ";
    print_bits(original_32bit_value);
    // Swap byte order of the given value
    uint32_t swapped_32bit_value{swap_byte_order(original_32bit_value)};
    std::cout << "Swapped value in decimal: " << swapped_32bit_value << "\n";
    std::cout << "Swapped value in bits: ";
    print_bits(swapped_32bit_value);

    // Exercise 3:
    std::cout << "\n----- Exercise 3: -----\n\n";
    uint8_t flags{IS_FUZZY | HAS_GOOGLY_EYES};
    print_set_options(flags);

    // Exercise 4:
    std::cout << "\n----- Exercise 4: -----\n\n";
    uint8_t combination_flags1{IS_FUZZY | HAS_GOOGLY_EYES};
    check_combinations(combination_flags1);

    uint8_t combination_flags2{HAS_TEETH | IS_ABOUT_TO_EAT_YOU};
    check_combinations(combination_flags2);

    uint8_t combination_flags3{IS_SPIDER | IS_FRIENDLY};
    check_combinations(combination_flags3);

    // Exercise 5:
    std::cout << "\n----- Exercise 5: -----\n\n";
    std::cout << "Enter a string (for example '123,43,55'): ";
    std::string input_string{};
    // To ignore the newline left in the buffer
    std::cin.ignore();
    std::getline(std::cin, input_string);
    // Goes through bytes in the string, and for each character of the string, marks the bit set if the character represents a comma. */
    uint32_t bits{create_bitmask_from_string(input_string)};
    std::cout << "Resulting bits: ";
    print_bits(bits);

    return 0;
}
