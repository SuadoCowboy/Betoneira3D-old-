#pragma once

#include "shared/shared.h"

#include "SOIL/soil.h"

#include <string>

namespace Betoneira
{
    class Texture
    {
    public:
        Texture();
        ~Texture();
    
        void load(const std::string& path);

        void bind();
        static void unbind();

    private:
        unsigned int id;
    };
}