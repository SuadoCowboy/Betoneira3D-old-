#pragma once

#include "shared/shared.h"
#include "shader/shader.h"
#include "texture/texture.h"

#include <string>

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

    class TextureMesh2D : public Mesh2D
    {
    public:
        template<size_t N, size_t N2>
        TextureMesh2D(Shader& shader, float (&vertices)[N], unsigned int (&indices)[N2], std::string path);
        
        ~TextureMesh2D();

        void draw();

    private:
        Texture texture;
    };

    /*
    class Mesh3D
    {
    public:
        template<size_t N, size_t N2>
        Mesh3D(Shader& shader, float (&vertices)[N], unsigned int (&indices)[N2]);
        ~Mesh3D();

        void draw();
    
    private:
        unsigned int vertexBuffer, indexBuffer, indicesLength;

        Shader* shader;
    }
    */
}

// unfortunately, it won't work on graphics.cpp
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

template<size_t N, size_t N2>
Betoneira::Graphics::TextureMesh2D::TextureMesh2D(Shader& shader, float (&vertices)[N], unsigned int (&indices)[N2], std::string path) : Mesh2D(shader, vertices, indices)
{
    texture.bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    texture.unbind();

    texture.load(path);
}