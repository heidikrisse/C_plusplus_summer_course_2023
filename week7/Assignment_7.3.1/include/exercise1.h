// exercise1.h
#ifndef EXERCISE1_H
#define EXERCISE1_H

// EqualityComparer class template to overload equality operator
template <typename T, typename U>
class EqualityComparer
{
public:
    bool operator()(const T &lhs, const U &rhs) const
    {
        return static_cast<T>(lhs) == static_cast<T>(rhs);
    }
};

#endif
