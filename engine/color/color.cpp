#include "color/color.h"

using namespace Betoneira;

Color::Color(){}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    color.x = r;
    color.y = g;
    color.z = b;
    color.w = a;
    
    updateGLColor();
}

Color::Color(int hexadecimal)
{
    setColor(hexToColor(hexadecimal));
}

Color::~Color(){}

Math::Vector4c& Color::getColor()
{
    return color;
}

Math::Vector4f& Color::getGLColor()
{
    return GLColor;
}

unsigned char Color::getR()
{
    return color.x;
}

unsigned char Color::getG()
{
    return color.y;
}

unsigned char Color::getB()
{
    return color.z;
}

unsigned char Color::getA()
{
    return color.w;
}

void Color::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    color.x = r;
    color.y = g;
    color.z = b;
    color.w = a;
    updateGLColor();
}

void Color::setColor(Color newColor)
{
    color.x = newColor.getR();
    color.y = newColor.getG();
    color.z = newColor.getB();
    color.w = newColor.getA();
    updateGLColor();
}

void Color::setColor(Math::Vector4c vector)
{
    color = vector;
    updateGLColor();
}

void Color::setGLColor(float r, float g, float b, float a)
{
    GLColor.x = r;
    GLColor.y = g;
    GLColor.z = b;
    GLColor.w = a;

    updateColor();
}

GLfloat Color::byteToFloat(unsigned char value)
{
    // FIMUL instruction
    // https://community.khronos.org/t/how-to-convert-from-rgb-255-to-opengl-float-color/29288/2
    return (1.0f/255) * value;
}

unsigned char Color::floatToByte(float value)
{
    return value * 255;
}

Color Color::hexToColor(int hexadecimalValue)
{
    // https://stackoverflow.com/questions/3723846/convert-from-hex-color-to-rgb-struct-in-c
    return { (unsigned char)((hexadecimalValue >> 16) & 0xFF), (unsigned char)((hexadecimalValue >> 8) & 0xFF), (unsigned char)((hexadecimalValue) & 0xFF) };
}

void Color::updateGLColor()
{
    GLColor.x = byteToFloat(color.x);
    GLColor.y = byteToFloat(color.y);
    GLColor.z = byteToFloat(color.z);
    GLColor.w = byteToFloat(color.w);
}

void Color::updateColor()
{
    color.x = floatToByte(GLColor.x);
    color.y = floatToByte(GLColor.y);
    color.z = floatToByte(GLColor.z);
    color.w = floatToByte(GLColor.w);
}