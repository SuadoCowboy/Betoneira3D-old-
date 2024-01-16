#include "file.h"

#include <iostream>
#include <sstream>

#include "shared/shared.h"
#include "os/os.h"

using namespace Betoneira;
using namespace FileSystem;

FileHandler::FileHandler(std::string _path) : path(_path) {};

FileHandler::FileHandler() : path("") {}
FileHandler::~FileHandler(){}

bool FileHandler::isOpen()
{
    return file.is_open();
}

bool FileHandler::open(openMode mode)
{
    if (path.size() == 0)
    {
        std::cerr << "ERROR: path could not be opened because size is 0" << std::endl;
        return true;
    }

    close();

    // creates file if it does not exists
    if (!System::pathExists(path))
    {
        std::ofstream f(path);
        f << "";
        f.close();
    }

    file.open(path.c_str(), mode);

    return !isOpen();
}

bool FileHandler::open(std::string newPath, openMode mode)
{
    path = newPath;
    return open(mode);
}

bool FileHandler::close()
{
    file.close();
    return isOpen();
}

bool FileHandler::write(const char* content)
{
    if (!isOpen())
    {
        std::cerr << "ERROR: file is not open to write to it" << std::endl;
        return true;
    }

    file << content;

    return false;
}

std::string FileHandler::read()
{
    if (!isOpen())
    {
        std::cerr << "ERROR: file is not open to read it" << std::endl;
        return "";
    }
    
    std::stringstream buf;
    buf << file.rdbuf();
    
    return buf.str();
}

std::string FileHandler::getPath()
{
    return path;
}

FileHandler& FileHandler::operator<<(const char* content)
{
    write(content);
    return *this;
}

bool FileSystem::getFileContent(const std::string& path, std::string& content, openMode mode)
{
    if (!System::isFile(path))
    {
        std::cerr << "ERROR::FILESYSTEM: path is not a file or does not exists" << std::endl;
        return 1;
    }

    FileHandler file{path};
    file.open(mode);

    content = file.read();
    
    file.close();

    return 0;
}