#include "texture.h"

using namespace Betoneira;

Texture::Texture()
{
    glGenTextures(1, &id);
}

Texture::~Texture()
{
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

void Texture::load(const std::string& path)
{
    id = SOIL_load_OGL_texture(path.c_str(), 4, 0, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y);
}