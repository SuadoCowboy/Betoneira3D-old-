#pragma once

#include "shared/shared.h"
#include <string>
#include "color/color.h"
#include "input/input.h"
#include <iostream>

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
        
        void fill(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
        void fill(Color color);
    };
}