#include "color/color.h"

using namespace Betoneira;

Color::Color(){}

Color::Color(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    
    updateGLColor();
}

Color::Color(int hexadecimal)
{
    setColor(Color::hexToColor(hexadecimal));
}

Color::~Color(){}

unsigned char Color::getR()
{
    return r;
}

unsigned char Color::getG()
{
    return g;
}

unsigned char Color::getB()
{
    return b;
}

unsigned char Color::getA()
{
    return a;
}

void Color::setColor(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    updateGLColor();
}

void Color::setColor(Color newColor)
{
    r = newColor.getR();
    g = newColor.getG();
    b = newColor.getB();
    a = newColor.getA();
    updateGLColor();
}

GLfloat Color::byteToGLfloat(unsigned char c)
{
    // FIMUL instruction
    // https://community.khronos.org/t/how-to-convert-from-rgb-255-to-opengl-float-color/29288/2
    return (1.0f/255) * c;
}

Color Color::hexToColor(int hexadecimalValue)
{
    // https://stackoverflow.com/questions/3723846/convert-from-hex-color-to-rgb-struct-in-c
    return { (unsigned char)((hexadecimalValue >> 16) & 0xFF), (unsigned char)((hexadecimalValue >> 8) & 0xFF), (unsigned char)((hexadecimalValue) & 0xFF) };
}

void Color::updateGLColor()
{
    GLr = byteToGLfloat(r);
    GLg = byteToGLfloat(g);
    GLb = byteToGLfloat(b);
    GLa = byteToGLfloat(a);
}