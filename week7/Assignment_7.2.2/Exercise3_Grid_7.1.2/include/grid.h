// grid.h
#ifndef GRID_H
#define GRID_H

#include <vector>
#include <cstddef> // for size_t
#include <tuple>
#include <iostream> // For std::cout and std::runtime_error

template <typename T, typename... Dims>
class Grid
{
public:
    // Typedefs
    using reference = T &;
    using const_reference = const T &;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;
    using size_type = std::size_t;
    using storage_type = std::vector<T>;
    using dimensions_type = std::tuple<Dims...>;

    // Constructor to create the Grid with specified dimensions and initialization value
    explicit Grid(Dims... dims, const T &grid_init_value)
        : dimensions_(dims...), data_((... * dims), grid_init_value) {}

    // Function templates for different dimensions:
    reference at(size_type x, size_type y)
    {
        if (x >= std::get<0>(dimensions_) || y >= std::get<1>(dimensions_))
        {
            throw std::runtime_error("Index out of grid bounds");
        }
        return data_[calculate_index(x, y)];
    }

    const_reference at(size_type x, size_type y) const
    {
        if (x >= std::get<0>(dimensions_) || y >= std::get<1>(dimensions_))
        {
            throw std::runtime_error("Index out of grid bounds");
        }
        return data_[calculate_index(x, y)];
    }

    reference at(size_type x, size_type y, size_type z)
    {
        if (x >= std::get<0>(dimensions_) || y >= std::get<1>(dimensions_) || z >= std::get<2>(dimensions_))
        {
            throw std::runtime_error("Index out of grid bounds");
        }
        return data_[calculate_index(x, y, z)];
    }

    const_reference at(size_type x, size_type y, size_type z) const
    {
        if (x >= std::get<0>(dimensions_) || y >= std::get<1>(dimensions_) || z >= std::get<2>(dimensions_))
        {
            throw std::runtime_error("Index out of grid bounds");
        }
        return data_[calculate_index(x, y, z)];
    }

    // Function to print the Grid contents
    void print_grid() const;

    iterator begin()
    {
        return data_.begin();
    }
    const_iterator begin() const
    {
        return data_.begin();
    }
    iterator end()
    {
        return data_.end();
    }
    const_iterator end() const
    {
        return data_.end();
    }

    // Functions to access and modify the Grid dimensions
    dimensions_type dimensions() const;

    void resize(Dims... new_dims);

    // Helper struct Size of the grid
    struct Size
    {
        size_type width{};
        size_type height{};
        size_type depth{};
    };
    Size size() const;

private:
    dimensions_type dimensions_;
    storage_type data_;

    // Helper functions to calculate the index from 2D or 3D coordinates:
    size_type calculate_index(size_type x, size_type y) const
    {
        auto [width, height]{dimensions_};
        return y * width + x;
    }

    size_type calculate_index(size_type x, size_type y, size_type z) const
    {
        auto [width, height, depth]{dimensions_};
        return (y * width + x) + (z * width * height);
    }
};

// Function template to print the Grid contents based on the number of dimensions
template <typename T, typename... Dims>
void Grid<T, Dims...>::print_grid() const
{
    // Printing for 2D Grid
    if constexpr (sizeof...(Dims) == 2)
    {
        std::cout << '\n';
        auto [width, height] = dimensions_;
        for (size_type y{0}; y < height; ++y)
        {
            for (size_type x{0}; x < width; ++x)
            {
                std::cout << at(x, y) << ' ';
            }
            std::cout << '\n';
        }
    }
    // Printing for 3D Grid
    else if constexpr (sizeof...(Dims) == 3)
    {
        std::cout << '\n';
        auto [width, height, depth] = dimensions_;
        for (size_type z{0}; z < depth; ++z)
        {
            // Add +1 to layer index to start it from 1
            std::cout << "Layer " << z + 1 << ":\n";
            for (size_type y{0}; y < height; ++y)
            {
                for (size_type x{0}; x < width; ++x)
                {
                    std::cout << at(x, y, z) << " ";
                }
                std::cout << '\n';
            }
        }
    }
}

// Function template to get the Grid dimensions
template <typename T, typename... Dims>
typename Grid<T, Dims...>::dimensions_type Grid<T, Dims...>::dimensions() const
{
    return dimensions_;
}

// Function template to resize the Grid based on new dimensions
template <typename T, typename... Dims>
void Grid<T, Dims...>::resize(Dims... new_dims)
{
    // Resizing for 2D Grid
    if constexpr (sizeof...(Dims) == 2)
    {
        dimensions_ = std::make_tuple(new_dims...);
        data_.resize((... * new_dims), T{}); // Set the new elements to default-initialized value
    }
    // Resizing for 3D Grid
    else if constexpr (sizeof...(Dims) == 3)
    {
        auto [old_width, old_height, old_depth] = dimensions_;
        auto [new_width, new_height, new_depth] = std::make_tuple(new_dims...);

        storage_type new_data(new_width * new_height * new_depth, T{});

        for (size_type z{0}; z < std::min(old_depth, new_depth); ++z)
        {
            for (size_type y{0}; y < std::min(old_height, new_height); ++y)
            {
                for (size_type x{0}; x < std::min(old_width, new_width); ++x)
                {
                    new_data[(y * new_width + x) + (z * new_width * new_height)] =
                        data_[(y * old_width + x) + (z * old_width * old_height)];
                }
            }
        }

        data_ = std::move(new_data);
        dimensions_ = std::make_tuple(new_dims...);
    }
}

// Function template to get the size of the Grid
template <typename T, typename... Dims>
typename Grid<T, Dims...>::Size Grid<T, Dims...>::size() const
{
    // If 2D grid
    if constexpr (sizeof...(Dims) == 2)
    {
        auto [width, height] = dimensions_;
        return {width, height, 0};
    }
    // If 3D grid
    else if constexpr (sizeof...(Dims) == 3)
    {
        auto [width, height, depth] = dimensions_;
        return {width, height, depth};
    }
    // else
    return {0, 0, 0}; // Invalid size for dimensions other than 2D or 3D
}

#endif
