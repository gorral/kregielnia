#pragma once

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;



struct TestFileSupport
{
    static bool CreateTestFiles(std::string inputfiles_directory);
    static bool RemoveTestFiles(std::string inputfiles_directory);
};
