#pragma once

#include "glad.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

namespace Betoneira
{
    enum Colors
    {
        // http://www.festra.com/cb/art-color.htm
        AQUA       = 0x00FFFF00,
        BLACK      = 0x00000000,
        BLUE       = 0x00FF0000,
        CREAM      = 0x00F0FBFF,
        GREY       = 0x00808080,
        FUCHSIA    = 0x00FF00FF,
        GREEN      = 0x00008000,
        LIMEGREEN  = 0x0000FF00,
        MAROON     = 0x00000080,
        NAVY       = 0x00800000,
        OLIVEGREEN = 0x00008080,
        PURPLE     = 0x00FF00FF,
        RED        = 0x000000FF,
        SILVER     = 0x00C0C0C0,
        TEAL       = 0x00808000,
        WHITE      = 0x00FFFFFF
    };

    class Color
    {
    public:
        Color();
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
        Color(int hexadecimal);
        ~Color();

        unsigned char getR();
        unsigned char getG();
        unsigned char getB();
        unsigned char getA();

        void setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
        void setColor(Color newColor);

        static GLfloat byteToGLfloat(unsigned char c);
        
        // for now, it doesn't support alpha values
        static Color hexToColor(int hexadecimalValue);
    private:
        unsigned char r = 0, g = 0, b = 0, a = 255;
        GLfloat GLr = 0.0f, GLg = 0.0f, GLb = 0.0f, GLa = 1.0f;

        void updateGLColor();
    };
}