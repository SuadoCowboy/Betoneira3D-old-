#pragma once

#include <string>

namespace Betoneira
{
    namespace File
    {
        std::string read(std::string path);
        void write(std::string path, std::string content);
    }
}