#pragma once

#ifndef PI
#define PI 3.1415926
#endif

#include "vector/vector.h"
#include "matrix/matrix.h"

namespace Betoneira::Math
{
    float degreesToRadians(float degrees);
    float radiansToDegrees(float radians);
}