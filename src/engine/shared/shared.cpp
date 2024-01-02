#include "shared/shared.h"

#include <process.h>

#include "glad.h"
#include <GLFW/glfw3.h>

void Betoneira::quit(int exitCode)
{
    glfwTerminate();
    exit(exitCode);
}