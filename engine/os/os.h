#pragma once

#include <string>
#include <boost/filesystem.hpp>

namespace Betoneira::System
{
    bool pathExists(std::string path);
    bool isDirectory(std::string path);
    bool isFile(std::string path);
}