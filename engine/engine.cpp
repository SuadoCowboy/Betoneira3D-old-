#include "engine.h"

#include <iostream>

void Betoneira::init()
{
    if (!glfwInit())
    {
        std::cerr << "ERROR::ENGINE: Could not initialize glfw" << std::endl;
        quit();
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    srand(time(NULL));
}