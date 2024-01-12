#include "graphics.h"

using namespace Betoneira::Graphics;

Mesh2D::~Mesh2D()
{
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &indexBuffer);
}

void Mesh2D::draw()
{
    shader->use();
    glDrawElements(GL_TRIANGLES, indicesLength, GL_UNSIGNED_INT, 0);
}