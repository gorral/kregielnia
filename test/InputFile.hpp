#pragma once

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;



struct InputFile
{
    static bool Create(std::string inputfiles_directory);
    static bool Remove(std::string inputfiles_directory);
};
