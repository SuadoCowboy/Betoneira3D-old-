#pragma once

#include <stdlib.h>
#include "color/color.h"

namespace Betoneira
{
    namespace Random
    {
        int randomInteger(int min, int max);
        Color randomColor(bool doAlpha = false);
    }
}