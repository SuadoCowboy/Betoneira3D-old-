#pragma once

#include <string>
#include "SOIL/soil.h"

namespace Betoneira
{
    class Texture
    {
    public:
        Texture();
        ~Texture();
    
        void load(const std::string& path, unsigned int soilFlags=SOIL_FLAG_MIPMAPS|SOIL_FLAG_INVERT_Y);
        void load(unsigned int id);

        void bind();
        static void unbind();

        unsigned int id;
    private:
        bool isAnotherTexture = false;
    };
}