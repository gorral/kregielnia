#pragma once

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;



struct InputFile
{
    static bool Create(fs::path const & inputfiles_directory);
    static bool Remove(fs::path const & inputfiles_directory);
};
