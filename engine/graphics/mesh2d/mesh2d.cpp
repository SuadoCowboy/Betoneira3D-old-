#include "Mesh2D.h"

using namespace Betoneira;
using namespace Graphics;

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

void Mesh2D::addAttribute(GLuint index, GLint size, float verticesLineLength, unsigned int lineIndex)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, verticesLineLength * sizeof(float), (void*)(lineIndex * sizeof(float)));
    glEnableVertexAttribArray(index);

    // unbind
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}