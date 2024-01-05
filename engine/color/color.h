#pragma once

#include "glad.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

namespace Betoneira
{
    class Color
    {
    public:
        Color();
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
        ~Color();

        unsigned char getR();
        unsigned char getG();
        unsigned char getB();
        unsigned char getA();

        void setRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);

        static GLfloat byteToGLfloat(unsigned char c);
    private:
        unsigned char r = 0, g = 0, b = 0, a = 255;
        GLfloat GLr = 0.0f, GLg = 0.0f, GLb = 0.0f, GLa = 1.0f;

        void updateGLColor();
    };
}