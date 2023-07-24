// grid.cpp
#include "../include/grid.h"
#include <iostream>

// EXERCISE 2:

template <typename T>
typename Grid<T>::reference Grid<T>::at(size_type x, size_type y)
{
    return data_[index(x, y)];
}

template <typename T>
typename Grid<T>::const_reference Grid<T>::at(size_type x, size_type y) const
{
    return data_[index(x, y)];
}

template <typename T>
void Grid<T>::print() const
{
    for (size_type y{0}; y < dimensions_.height; ++y)
    {
        for (size_type x{0}; x < dimensions_.width; ++x)
        {
            std::cout << at(x, y) << " ";
        }
        std::cout << "\n";
    }
}

// EXERCISE 3:

template <typename T>
typename Grid<T>::iterator Grid<T>::begin()
{
    return data_.begin();
}

template <typename T>
typename Grid<T>::const_iterator Grid<T>::begin() const
{
    return data_.begin();
}

template <typename T>
typename Grid<T>::iterator Grid<T>::end()
{
    return data_.end();
}

template <typename T>
typename Grid<T>::const_iterator Grid<T>::end() const
{
    return data_.end();
}

// EXERCISE 4:

template <typename T>
typename Grid<T>::dimension_type Grid<T>::size() const
{
    return dimensions_;
}

template <typename T>
void Grid<T>::resize(size_type new_width, size_type new_height)
{
    storage_type new_data(new_width * new_height);
    for (size_type y{0}; y < std::min(dimensions_.height, new_height); ++y)
    {
        for (size_type x{0}; x < std::min(dimensions_.width, new_width); ++x)
        {
            new_data[y * new_width + x] = at(x, y);
        }
    }
    data_ = new_data;
    dimensions_.width = new_width;
    dimensions_.height = new_height;
}

template <typename T>
typename Grid<T>::size_type Grid<T>::index(size_type x, size_type y) const
{
    if (x >= dimensions_.width || y >= dimensions_.height)
    {
        throw std::runtime_error("Index out of grid bounds");
    }
    return y * dimensions_.width + x;
}

// Explicit instantiation
template class Grid<int>;
