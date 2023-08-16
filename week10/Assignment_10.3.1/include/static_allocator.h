// static_allocator.h
#ifndef STATIC_ALLOCATOR_H
#define STATIC_ALLOCATOR_H

#include <cstddef> // For std::size_t
#include <cstdint> // For std::uint8_t
#include <new>     // For placement new

// The size of the statically allocated memory block
constexpr std::size_t SIZE{1024};

template <typename T>
class StaticAllocator
{
private:
    std::uint8_t memory_block[SIZE];
    std::size_t used_memory{};

public:
    using value_type = T;

    StaticAllocator() = default;

    // Allocate memory from the statically allocated memory block for constructing an object
    T *allocate(std::size_t n)
    {
        // If not enough memory to allocate, return nullptr
        if (sizeof(T) * n + used_memory > SIZE)
        {
            return nullptr;
        }

        void *result = &memory_block[used_memory];
        used_memory += sizeof(T) * n;

        return static_cast<T *>(result);
    }

    // Deallocate memory for destructing object
    void deallocate(T *p, std::size_t n)
    {
        //
    }

    // Compare allocators (always return true since we have a single block of memory)
    bool operator==(const StaticAllocator<T> &) const
    {
        return true;
    }

    bool operator!=(const StaticAllocator<T> &other) const
    {
        return !(*this == other);
    }
};

#endif
