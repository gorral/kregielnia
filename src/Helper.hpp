#pragma once

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;



struct Helper
{
    static const std::string INPUT_FILES_DIRECTORY;
    static bool CreateTestFiles();
    static bool RemoveTestFiles();
};
