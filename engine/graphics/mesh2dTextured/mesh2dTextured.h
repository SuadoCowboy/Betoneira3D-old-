#pragma once

#include "shared/shared.h"
#include "graphics/shader/shader.h"
#include "graphics/texture/texture.h"
#include "graphics/mesh2d/mesh2d.h"

#include <string>

namespace Betoneira::Graphics
{
    class Mesh2DTextured : public Mesh2D
    {
    public:
        template<size_t N, size_t N2>
        Mesh2DTextured(Shader& shader, float (&vertices)[N], unsigned int (&indices)[N2], std::string path);
        
        ~Mesh2DTextured();

        void draw();

        Texture& getTexture();

    private:
        Texture texture;
    };
}

template<size_t N, size_t N2>
Betoneira::Graphics::Mesh2DTextured::Mesh2DTextured(Shader& shader, float (&vertices)[N], unsigned int (&indices)[N2], std::string path) : Mesh2D(shader, vertices, indices)
{
    texture.bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    texture.unbind();

    texture.load(path);
}