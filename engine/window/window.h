#pragma once

#include "shared/shared.h"
#include "color/color.h"
#include "math/vector/vector.h"

#include <string>
#include <iostream>

namespace Betoneira
{
    class Window
    {
    public:
        static GLFWwindow* glfwWindow;
        
        static void init(int width, int height, const std::string& title);

        static void setSize(int width, int height);
        static void setSize(const Math::Vector2i& size);
        static void setSize(const Math::Vector2u& size);
        static void setSize(const Math::Vector2f& size);

        static void setTitle(const char* title);

        static bool shouldClose();
        static void close();
        static void clear();
        
        static void fill(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
        static void fill(Color color);
    private:
        Window();
        ~Window();
    };
}