/* memerror2.h
 *
 * ---------- Exercise 1: ----------
 *
 * int -> no error, because int is a simple data type and reinterpret_cast
 * be used with int array
 *
 * std::string -> a segmentation fault "SEGV" error.
 *
 * ==32805==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000001 (pc 0x7fae058c4a68 bp 0x7fff2788ee80 sp 0x7fff2788ee58 T0)
==32805==The signal is caused by a WRITE memory access.
==32805==Hint: address points to the zero page.

 *             -> std::string dynamically manages memory and can handle
 *                different size strings and because the buffer in flawed array
 *                is fixed-size, it can handle strings that are larger than the
 *                buffer size and strings can be larger than the fized-size
 *                buffer in the array.
 *
 * */
#ifndef MEMERROR2_H
#define MEMERROR2_H

#include <new>
#include <cstdint>
#include <iostream>
#include <string> // Exercise 1: added for std::string

// This is pretty much a poor man's std::array (with some not-immediately-obvious memory problems)
template <typename T, std::size_t Count>
class flawed_array
{
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using const_pointer = const T *;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using size_type = std::size_t;

    /*
     * ---------- Exercise 3: ----------
     * */

    /*
     * Before:
     *
    constexpr flawed_array() = default;

    // unchecked access
    constexpr reference operator[](const std::size_t index) noexcept
    {
        return reinterpret_cast<reference>(*(data_storage + index * sizeof(value_type)));
    }

    constexpr const_reference operator[](const std::size_t index) const noexcept
    {
        return reinterpret_cast<const_reference>(*(data_storage + index * sizeof(value_type)));
    }

    constexpr iterator begin() noexcept { return reinterpret_cast<pointer>(data_storage); }
    constexpr const_iterator begin() const noexcept { return reinterpret_cast<pointer>(data_storage); }

    constexpr iterator end() noexcept { return reinterpret_cast<pointer>(data_storage + sizeof(value_type) * Count); }
    constexpr const_iterator end() const noexcept { return reinterpret_cast<const_pointer>(data_storage + sizeof(value_type) * Count); }

    constexpr size_type size() const noexcept { return Count; }

private:
    // Create buffer of unsigned byte array (plain data), correctly aligned
    // and large enough to hold Count elements.  The data is uninitialised.
    // This is basically a way to reserve stack memory.
    alignas(value_type) uint8_t data_storage[sizeof(value_type) * Count];

    // The alignas needs to be there so the memory is correctly aligned, we
    // aren't going to go deeper into that, but it can cause *really* hard to
    // debug errors if that isn't there.
};
*/

    /*
     * After:
     *
     * Corrected to dynamically allocate memory.
     * */

    // Default constructor
    flawed_array() : data_storage(new value_type[Count]) {}

    // Copy constructor
    flawed_array(const flawed_array &other)
    {
        data_storage = new value_type[Count];
        for (std::size_t i = 0; i < Count; ++i)
        {
            data_storage[i] = other.data_storage[i];
        }
    }

    // Destructor
    ~flawed_array()
    {
        delete[] data_storage;
    }

    // Corrected returns:

    reference operator[](const std::size_t index) noexcept
    {
        return data_storage[index];
    }

    const_reference operator[](const std::size_t index) const noexcept
    {
        return data_storage[index];
    }

    iterator begin() noexcept
    {
        return data_storage;
    }

    const_iterator begin() const noexcept
    {
        return data_storage;
    }

    iterator end() noexcept
    {
        return data_storage + Count;
    }

    const_iterator end() const noexcept
    {
        return data_storage + Count;
    }

    size_type size() const noexcept
    {
        return Count;
    }

private:
    value_type *data_storage;
};

#endif
