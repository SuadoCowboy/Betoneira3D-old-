#include "texture.h"

#include "shared/shared.h"

using namespace Betoneira;

Texture::Texture()
{
    glGenTextures(1, &id);
}

Texture::~Texture()
{
    if (!isAnotherTexture)
        glDeleteTextures(1, &id);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::load(const std::string& path, unsigned int soilFlags)
{
    id = SOIL_load_OGL_texture(path.c_str(), 4, 0, soilFlags);
}

void Texture::load(unsigned int _id)
{
    glDeleteTextures(0, &id);
    id = _id;
    isAnotherTexture = true;
}