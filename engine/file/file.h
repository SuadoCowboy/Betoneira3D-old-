#pragma once

#include <string>

namespace Betoneira
{
    class FileHandler
    {
        FileHandler();
        ~FileHandler();
        
        virtual std::string read(std::string path);
        virtual void write(std::string path, std::string content);
    }
}