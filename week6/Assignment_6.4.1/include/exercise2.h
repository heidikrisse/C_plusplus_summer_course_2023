// exercise2.h
#ifndef EXERCISE2_H
#define EXERCISE2_H

#include <iostream>

// Namespace declaration for a 3D vector type
namespace vector_namespace
{

    class Vector3D
    {
    public:
        float x{};
        float y{};
        float z{};
    };

    // operator overloads
    std::ostream &operator<<(std::ostream &out, const Vector3D &vec);

}

#endif
