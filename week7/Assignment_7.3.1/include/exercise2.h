// exercise2.h
#ifndef EXERCISE2_H
#define EXERCISE2_H

#include "exercise1.h"

/* Comparer class template using CRTP pattern which inherits
 * equality functionality from EqualityComparer
 * - other comparison operators are added here */
template <typename Derived>
struct Comparer : EqualityComparer<Derived, Derived>
{
    // overloading
    bool operator!=(const Derived &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Derived &other) const
    {
        return static_cast<const Derived *>(this)->Derived::operator<(other);
    }

    bool operator>(const Derived &other) const
    {
        return other < static_cast<const Derived &>(*this);
    }

    bool operator<=(const Derived &other) const
    {
        return !(static_cast<const Derived &>(*this) > other);
    }

    bool operator>=(const Derived &other) const
    {
        return !(static_cast<const Derived &>(*this) < other);
    }
};

// ValueType has overloaded comparison operators and a private value
template <typename T>
class ValueType : public Comparer<ValueType<T>>
{
public:
    ValueType(T val) : value(val) {}

    // Overloading operators
    bool operator==(const ValueType<T> &other) const
    {
        return value == other.value;
    }

    bool operator<(const ValueType<T> &other) const
    {
        return value < other.value;
    }

    /* Print the stored value here to avoid needing ostream and the need
     * to overload << operator for ValueType<T> */
    void print_value() const
    {
        std::cout << value << '\n';
    }

private:
    T value;
};

#endif
