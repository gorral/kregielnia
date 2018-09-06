#include "InputFile.hpp"

bool InputFile::Create(std::string inputfiles_directory)
{
    fs::remove_all(inputfiles_directory);

    bool res = fs::create_directory(inputfiles_directory);
    if(not res)
        return false;

    fs::path testfile_path = fs::current_path() /= inputfiles_directory;

    testfile_path /= "TestFile_1.txt";
    std::ofstream testfile1(testfile_path.c_str());
    if(testfile1) {
        testfile1 << "Name1:X|4-|3"  << std::endl;
        testfile1 << "Name2:34|X|0-" << std::endl;
        testfile1 << ":X|22|33"      << std::endl;
    }
    if(testfile1.bad())
        return false;

    /* Create "TestFile_xx" */
    // TODO:: Set implementation for next TestFiles!

    return true;
}

bool InputFile::Remove(std::string inputfiles_directory)
{   
    return fs::remove_all(inputfiles_directory);
}
