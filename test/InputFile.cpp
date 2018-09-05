#include "InputFile.hpp"

bool InputFile::Create(std::string inputfiles_directory)
{
    //TODO:: remove cout in release version!
    if(fs::remove_all(inputfiles_directory)) {
        std::cout << "Warning: old inputfiles_directory was deleted!" << std::endl;
    } else {
        std::cout << "Info:: Inputfiles_directory does not exist end will be created!" << std::endl;
    }

    bool res = fs::create_directory(inputfiles_directory);
    if(not res) {
        std::cout << "Error: Can not create inputfile_directory" << std::endl;
        return false;
    }

    fs::path testfile_path = fs::current_path() /= inputfiles_directory;

    /* Create "TestFile_1" */
    testfile_path /= "TestFile_1.txt";
    std::ofstream testfile1(testfile_path.c_str());
    if(testfile1) {
        testfile1 << "Name1:X|4-|3"  << std::endl;
        testfile1 << "Name2:34|X|0-" << std::endl;
        testfile1 << ":X|22|33"      << std::endl;
    }
    if(testfile1.bad()) {
        std::cout<<"Writing to file failed"<<std::endl;
        return false;
    }

    /* Create "TestFile_xx" */
    // TODO:: Set implementation for next TestFiles!

    //TODO: remove
    for(auto& p: fs::directory_iterator(inputfiles_directory))
        std::cout << "path: "<< p << '\n';
    return true;
}

bool InputFile::Remove(std::string inputfiles_directory)
{   
    return fs::remove_all(inputfiles_directory);
}
