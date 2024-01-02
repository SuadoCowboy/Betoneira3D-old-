#include "file.h"

#include <fstream>
#include <sstream>

using namespace Betoneira;

FileHandler::FileHandler(){};
FileHandler::~FileHandler(){};

std::string FileHandler::read(std::string path)
{
    std::ifstream file(path);
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    
    return buffer.str();
}

void FileHandler::write(std::string path, std::string content)
{

}