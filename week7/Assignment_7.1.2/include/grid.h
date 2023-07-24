// grid.h
#ifndef GRID_H
#define GRID_H

#include <vector>
#include <cstddef> // for size_t

// Exercise 1 and 1.5:
template <typename T>
class Grid
{
public:
    // Type aliases for container specification
    using reference = T &;
    using const_reference = const T &;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;
    using size_type = std::size_t;

    using storage_type = std::vector<T>;
    using dimension_type = struct
    {
        size_type width;
        size_type height;
    };

    Grid(size_type width, size_type height, const T &grid_init_value)
        : dimensions_{width, height}, data_(width * height, grid_init_value) {}

    // Exercise 2:
    reference at(size_type x, size_type y);
    const_reference at(size_type x, size_type y) const;
    void print() const;

    // Exercise 3:
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    // Exercise 4:
    dimension_type size() const;
    void resize(size_type new_width, size_type new_height);

private:
    dimension_type dimensions_;
    storage_type data_;

    size_type index(size_type x, size_type y) const;
};

#endif
