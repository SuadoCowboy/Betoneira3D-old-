#include "time.h"

#include "shared/shared.h"

using namespace Betoneira;

std::chrono::system_clock::time_point Time::getSystemTime()
{
    return std::chrono::high_resolution_clock::now();
}

float Time::getTime()
{
    return glfwGetTime();
}