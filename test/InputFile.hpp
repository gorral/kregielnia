#pragma once

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;



struct InputFile
{
    static bool Create(std::string const & inputfiles_directory);
    static bool Remove(std::string const & inputfiles_directory);
};
