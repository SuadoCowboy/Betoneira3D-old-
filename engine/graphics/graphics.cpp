#include "graphics.h"

using namespace Betoneira;

Graphics2D::Mesh::~Mesh()
{
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &elementBuffer);
}

void Graphics2D::Mesh::draw()
{
    shader->use();
    glDrawElements(GL_TRIANGLES, indicesLength, GL_UNSIGNED_INT, 0);
}