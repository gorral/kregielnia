#include "Helper.hpp"

const std::string Helper::INPUT_FILES_DIRECTORY = "test_files";

bool Helper::CreateTestFiles()
{
    //TODO: add Error handling
    fs::create_directories(INPUT_FILES_DIRECTORY);
    fs::path p1;
    p1 /= INPUT_FILES_DIRECTORY;


    // Create first test file
    std::cout<<"File 'TestFile_1' is created" << std::endl;
    p1 /= "TestFile_1.txt";
    std::ofstream testfile1(p1);
    testfile1 << "Name1:X|4-|3"  << std::endl;
    testfile1 << "Name2:34|X|0-" << std::endl;
    testfile1 << ":X|22|33"      << std::endl;

    for(auto& p: fs::directory_iterator(INPUT_FILES_DIRECTORY))
        std::cout << "path: "<< p << '\n';
    return true;
}

bool Helper::RemoveTestFiles()
{
     //TODO: add Error handling
    std::cout << "Removed all test files from: "<< Helper::INPUT_FILES_DIRECTORY<< std::endl;
    fs::remove_all(INPUT_FILES_DIRECTORY);
    return true;
}
