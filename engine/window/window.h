#pragma once

#include "glad.h"
#include <GLFW/glfw3.h>
#include <string>

namespace Betoneira
{
    class Window
    {
    public:
        GLFWwindow* glfwWindow = nullptr;

        Window(int width, int height, std::string title);
        ~Window();

        bool shouldClose();
        void close();
        void clear();
        void fill(float r, float g, float b, float a);
        void fill(float r, float g, float b);
    };
}