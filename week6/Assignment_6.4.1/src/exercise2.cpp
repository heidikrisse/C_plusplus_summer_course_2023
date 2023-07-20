// exercise2.cpp
#include "exercise2.h"

namespace vector_namespace
{

    std::ostream &operator<<(std::ostream &output, const Vector3D &vec)
    {
        output << "Vector3D(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return output;
    }

}
