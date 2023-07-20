// exercise3.cpp
#include "exercise3.h"

namespace vector_namespace
{

    Vector3D operator+(const Vector3D &left, const Vector3D &right)
    {
        return {left.x + right.x, left.y + right.y, left.z + right.z};
    }

    Vector3D operator-(const Vector3D &left, const Vector3D &right)
    {
        return {left.x - right.x, left.y - right.y, left.z - right.z};
    }

    Vector3D &operator+=(Vector3D &left, const Vector3D &right)
    {
        left.x += right.x;
        left.y += right.y;
        left.z += right.z;
        return left;
    }

    Vector3D &operator-=(Vector3D &left, const Vector3D &right)
    {
        left.x -= right.x;
        left.y -= right.y;
        left.z -= right.z;
        return left;
    }

}
