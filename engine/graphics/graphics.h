#pragma once

#include "shared/shared.h"
#include "shader/shader.h"

namespace Betoneira::Graphics2D
{
    class Mesh
    {
    public:
        template<size_t N, size_t N2>
        Mesh(Shader& shader, float (&vertices)[N], unsigned int (&indices)[N2]);
        ~Mesh();

        void draw();
    
    private:
        unsigned int vertexBuffer, elementBuffer, indicesLength;

        Shader* shader;
    };
}

/*namespace Betoneira::Graphics3D
{
    class Mesh
    {
    }
}
*/

// unfortunately, it won't work on graphics.cpp
template<size_t N, size_t N2>
Betoneira::Graphics2D::Mesh::Mesh(Shader& _shader, float (&vertices)[N], unsigned int (&indices)[N2])
{
    shader = &_shader;

    indicesLength = sizeof(indices)/sizeof(indices[0]);

    // generate
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &elementBuffer);

    // bind
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);

    // set data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // unbind
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}