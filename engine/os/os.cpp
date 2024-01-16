#include "os.h"

#include <boost/filesystem.hpp>

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

std::string System::baseName(std::string _path)
{
    boost::filesystem::path p{_path};
    return p.stem().string();
}

std::string System::fileExtension(std::string _path)
{
    boost::filesystem::path p{_path};
    return p.extension().string().substr(1);
}