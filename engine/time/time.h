#pragma once

#include <chrono>

namespace Betoneira::Time
{
    // returns the OS time
    std::chrono::system_clock::time_point getSystemTime();

    // returns the time passed since glfw was initialized
    float getTime();
}