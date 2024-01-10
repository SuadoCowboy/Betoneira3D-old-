#include "graphics.h"

using namespace Betoneira;

Graphics2D::Triangle::Triangle(Shader& _shader, const Math::Vector2f& point1, const Math::Vector2f& point2, const Math::Vector2f& point3)
{
    float vertices[] = {
        point1.x, point1.y, 0.0f,
        point2.x, point2.y, 0.0f,
        point3.x, point3.y, 0.0f
    };

    shader = &_shader;

    // TODO: make all of this into render class?

    // generate
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // bind
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    
    // unbind
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Graphics2D::Triangle::~Triangle(){}

void Graphics2D::Triangle::draw(Window& window)
{
    shader->use();
    glfwMakeContextCurrent(window.glfwWindow);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Graphics2D::Triangle::updateShaderColor()
{
    shader->setVector4f("color", color.getGLColor());
}

void Graphics2D::Triangle::setGLColor(float r, float g, float b, float a)
{
    color.setGLColor(r, g, b, a);
    updateShaderColor();
}

void Graphics2D::Triangle::setColor(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
    color.setColor(r, g, b, a);
    updateShaderColor();
}

void Graphics2D::Triangle::setColor(Color color)
{
    color.setColor(color);
    updateShaderColor();
}

void Graphics2D::Triangle::setColor(Math::Vector4c vector)
{
    color.setColor(vector);
    updateShaderColor();
}

Color& Graphics2D::Triangle::getColor()
{
    return color;
}