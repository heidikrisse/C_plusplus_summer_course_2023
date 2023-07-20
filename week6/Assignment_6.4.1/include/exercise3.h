// exercise3.h
#ifndef EXERCISE3_H
#define EXERCISE3_H

#include "exercise2.h"

namespace vector_namespace
{
    // Operator overloads for the 3D vector type (defined in exercise2)
    Vector3D operator+(const Vector3D &left, const Vector3D &right);
    Vector3D operator-(const Vector3D &left, const Vector3D &right);
    Vector3D &operator+=(Vector3D &left, const Vector3D &right);
    Vector3D &operator-=(Vector3D &left, const Vector3D &right);

}

#endif
