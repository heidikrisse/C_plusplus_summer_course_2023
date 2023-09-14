// heap_array.h
#ifndef HEAP_ARRAY_H
#define HEAP_ARRAY_H

#include <stdexcept> // for std::runtime_error
#include <algorithm> // for std::swap
#include <iterator>  // for std::distance
#include <limits>

template <typename T>
class HeapArray
{
private:
    // --- Exercise 1: ---

    T *data_;
    // Size of the heap array
    std::size_t size_{};

public:
    // Type aliases:
    using value_type = T;
    using iterator = T *;
    using const_iterator = const T *;

    // --- Exercise 2: ---

    // Default constructor
    HeapArray() : data_(nullptr), size_(0) {}

    // Constructor with arguments
    HeapArray(std::size_t size) : data_(new T[size]{}), size_(size) {}

    // Copy constructor
    HeapArray(const HeapArray &other) : data_(new T[other.size_]), size_(other.size_)
    {
        for (std::size_t i{0}; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    // Move constructor
    HeapArray(HeapArray &&other) noexcept : data_(other.data_), size_(other.size_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
    }

    // Copy assignment operator
    HeapArray &operator=(const HeapArray &other)
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = new T[other.size_];
            size_ = other.size_;
            for (std::size_t i{0}; i < size_; ++i)
            {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    // Move assignment operator
    HeapArray &operator=(HeapArray &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            other.data_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    // Destructor
    ~HeapArray()
    {
        delete[] data_;
    }

    // --- Exercise 3: ---

    // Operator[] for element access
    T &operator[](std::size_t index)
    {
        return data_[index];
    }

    const T &operator[](std::size_t index) const
    {
        return data_[index];
    }

    // at() method for range-checked element access
    T &at(std::size_t index)
    {
        if (index >= size_)
        {
            throw std::runtime_error("Index out of range!");
        }
        return data_[index];
    }

    const T &at(std::size_t index) const
    {
        if (index >= size_)
        {
            throw std::runtime_error("Index out of range!");
        }
        return data_[index];
    }

    // --- Exercise 4: ---

    // Function to swap two arrays
    void swap(HeapArray &other) noexcept
    {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
    }

    // --- Exercise 5: ===

    // Rest of the container requirements:

    // Function to check if container is empty
    bool empty() const
    {
        return size_ == 0;
    }

    // Function to return the size of the container
    std::size_t size() const
    {
        return size_;
    }

    // Function to clear the container (doesn't deallocate memory but sets size to 0)
    void clear()
    {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
    }

    // Relational operators == and !=
    // Equality operator (==)
    bool operator==(const HeapArray &other) const
    {
        if (size_ != other.size_)
        {
            return false;
        }

        for (std::size_t i{0}; i < size_; ++i)
        {
            if (data_[i] != other.data_[i])
            {
                return false;
            }
        }

        return true;
    }

    // Inequality operator (!=)
    bool operator!=(const HeapArray &other) const
    {
        return !(*this == other);
    }

    // Max size
    std::size_t max_size() const
    {
        return std::numeric_limits<std::size_t>::max();
    }

    // Global swap function
    void swap(HeapArray<T> &a, HeapArray<T> &b)
    {
        a.swap(b);
    }

    // Iterator methods
    iterator begin()
    {
        return data_;
    }

    const_iterator begin() const
    {
        return data_;
    }

    const_iterator cbegin() const
    {
        return data_;
    }

    iterator end()
    {
        return data_ + size_;
    }

    const_iterator end() const
    {
        return data_ + size_;
    }

    const_iterator cend() const
    {
        return data_ + size_;
    }
};

#endif
