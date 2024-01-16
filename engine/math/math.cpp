#include "math.h"

#include <math.h>

using namespace Betoneira:

float Math::degreesToRadians(float degrees)
{
    return degrees * (PI / 180);
}

float Math::radiansToDegrees(float radians)
{
    return radians * (180 / PI);
}