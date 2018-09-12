#include "InputFile.hpp"

bool InputFile::Create(std::string const &inputfiles_directory)
{
    fs::remove_all(inputfiles_directory);

    bool res = fs::create_directory(inputfiles_directory);
    if(not res) {
        return false;
    }

    fs::path testfile_path = fs::current_path() /= inputfiles_directory;

    testfile_path /= "TestFile_1.txt";
    std::ofstream testfile1(testfile_path.c_str());
    if(testfile1) {
        testfile1 << "Name1:X|4-|3"  << std::endl;
        testfile1 << "Name2:34|X|0-" << std::endl;
        testfile1 << ":X|22|33"      << std::endl;
    }
    if(testfile1.bad()) {
        return false;
    }

    testfile_path = fs::current_path() /= inputfiles_directory;
    testfile_path /= "TestFile_2.txt";
    std::ofstream testfile2(testfile_path.c_str());
    if(testfile2) {
        testfile2 << "Name3:X|5-|7-"  << std::endl;
        testfile2 << "Name4:34|X|0-"  << std::endl;
        testfile2 << "Name5:23|43|51" << std::endl;
    }
    if(testfile2.bad()) {
        return false;
    }

    return true;
}

bool InputFile::Remove(std::string const &inputfiles_directory)
{   
    return fs::remove_all(inputfiles_directory);
}
