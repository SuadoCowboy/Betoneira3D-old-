#include "file.h"

#include <fstream>
#include <sstream>

using namespace Betoneira;

std::string File::read(std::string path)
{
    std::ifstream file(path);
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    
    return buffer.str();
}

void File::write(std::string path, std::string content)
{

}