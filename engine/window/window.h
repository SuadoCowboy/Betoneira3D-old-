#pragma once

#include "shared/shared.h"
#include "color/color.h"
#include "input/input.h"
#include "math/vector/vector.h"

#include <string>
#include <iostream>

namespace Betoneira
{
    class Window
    {
    public:
        GLFWwindow* glfwWindow = nullptr;
        
        Window(int width, int height, const std::string& title);
        
        Window(const Math::Vector2i& size, const std::string& title);
        Window(const Math::Vector2u& size, const std::string& title);
        Window(const Math::Vector2f& size, const std::string& title);
        
        ~Window();

        bool shouldClose();
        void close();
        void clear();
        
        void fill(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
        void fill(Color color);
    private:
        void init(int width, int height, const std::string& title);
    };
}