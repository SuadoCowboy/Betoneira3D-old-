#include "file.h"

using namespace Betoneira;

bool FileHandler::pathExists(std::string path)
{
    // to read metadata
    struct stat info;

    if (stat(path.c_str(), &info) == 0)
        return true;
    else
        return false;

}

FileHandler::FileHandler(std::string _path)
{
    path = _path;
};

FileHandler::FileHandler(){}
FileHandler::~FileHandler(){}

bool FileHandler::isOpen()
{
    return file.is_open();
}

bool FileHandler::open(std::ios_base::openmode mode)
{
    if (path.size() == 0)
    {
        std::cerr << "ERROR: path could not be opened because size is 0" << std::endl;
        return true;
    }

    // creates file if it does not exists
    if (!pathExists(path))
    {
        std::ofstream f(path);
        f << "";
        f.close();
    }

    file.open(path.c_str(), mode);

    return !isOpen();
}

bool FileHandler::open(std::string newPath, std::ios_base::openmode mode)
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

FileHandler& operator<<(FileHandler& file, const char* content)
{
    file.write(content);
    return file;
}