#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "os/os.h"

namespace Betoneira
{
    namespace FileSystem
    {
        typedef std::ios_base::openmode openMode;
        static const openMode FILE_READ = (openMode)8;
        static const openMode FILE_WRITE = (openMode)16;

        class FileHandler
        {
        public:
            FileHandler(std::string path);
            FileHandler();
            ~FileHandler();
            
            // return 1 if error
            bool open(openMode mode);
            
            // return 1 if error
            bool open(std::string path, openMode mode);
            
            // return 1 if open
            inline bool isOpen();
            
            // return 1 if error
            bool close();
            
            std::string getPath();

            // return 1 if error
            virtual bool write(const char* content);

            // if you wrote something to it then close and open again to read the updated file
            std::string read();

            FileHandler& operator<<(const char* content);
        
        private:
            std::fstream file;
            std::string path{};
        };
    }
}