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

void Color::setRGBA(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    updateGLColor();
}

GLfloat Color::byteToGLfloat(unsigned char c)
{
    // FIMUL instruction
    // https://community.khronos.org/t/how-to-convert-from-rgb-255-to-opengl-float-color/29288/2
    return (1.0f/255) * c;
}

void Color::updateGLColor()
{
    GLr = byteToGLfloat(r);
    GLg = byteToGLfloat(g);
    GLb = byteToGLfloat(b);
    GLa = byteToGLfloat(a);
}