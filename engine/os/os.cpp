#include "os.h"

using namespace Betoneira;

bool System::pathExists(std::string path)
{
    return boost::filesystem::exists(path);
}

bool System::isDirectory(std::string path)
{
    return boost::filesystem::is_directory(path);
}

bool System::isFile(std::string path)
{
    return boost::filesystem::is_regular_file(path);
}