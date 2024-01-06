#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "os/os.h"

namespace Betoneira
{
    class FileHandler
    {
    public:
        std::string path{};

        FileHandler(std::string path);
        FileHandler();
        ~FileHandler();
        
        // return 1 if error
        virtual bool open(std::ios_base::openmode mode);
        
        // return 1 if error
        virtual bool open(std::string path, std::ios_base::openmode mode);
        
        // return 1 if open
        virtual inline bool isOpen();
        
        // return 1 if error
        virtual bool close();
        
        // return 1 if error
        virtual bool write(const char* content);

        // should be closed and opened again to read the updated file(if you wrote something to it)
        virtual std::string read();
    private:
        std::fstream file;
    };
}

Betoneira::FileHandler& operator<<(Betoneira::FileHandler& file, const char* content);