#pragma once

#include "shared/shared.h"
#include "graphics/shader/shader.h"
#include "graphics/texture/texture.h"

namespace Betoneira::Graphics
{
    class Mesh2D
    {
    public:
        template<size_t N, size_t N2>
        Mesh2D(Shader& shader, float (&vertices)[N], unsigned int (&indices)[N2]);
        
        ~Mesh2D();

        void draw();

        void addAttribute(GLuint index, GLint size, float verticesLineLength, unsigned int lineIndex);

    private:
        unsigned int vertexBuffer, indexBuffer, indicesLength;

        Shader* shader;
    };
}

template<size_t N, size_t N2>
Betoneira::Graphics::Mesh2D::Mesh2D(Shader& _shader, float (&vertices)[N], unsigned int (&indices)[N2])
{
    shader = &_shader;

    indicesLength = sizeof(indices)/sizeof(indices[0]);

    // generate
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &indexBuffer);

    // bind
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

    // set data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}