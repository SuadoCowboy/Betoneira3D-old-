#pragma once

// include every engine stuff inside this header
#include "window/window.h"
#include "shared/shared.h"
#include "shader/shader.h"
#include "file/file.h"
#include "color/color.h"
#include "input/input.h"
#include "random/random.h"
#include "os/os.h"
#include "math/math.h" // already includes everything inside math folder
#include "render/render.h"
#include "graphics/graphics.h"
#include "time/time.h"

namespace Betoneira
{
    void init();
}