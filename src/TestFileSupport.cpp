#include "TestFileSupport.hpp"
#include <system_error>
#include <cerrno>

bool TestFileSupport::CreateTestFiles(std::string inputfiles_directory)
{
    //TODO: add Error handling
    errno = 0;
    std::error_code ec(errno, std::generic_category());
    if(fs::is_directory(inputfiles_directory)) {
        fs::remove_all(inputfiles_directory, ec);
        if(ec.value() != 0) {
            std::cout << "Error: " << ec.message() << std::endl;
            return false;
        }
    }

    fs::create_directories(inputfiles_directory, ec);
    if(ec.value() != 0) {
        std::cout << "Error: " << ec.message() << std::endl;
        return false;
    }

    fs::path testfile_path = fs::current_path() /= inputfiles_directory;

    // Create first test file
    //TODO: REMOVE cout in final version!!!
    std::cout<<"File 'TestFile_1' is created" << std::endl;
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

    //TODO: remove
    for(auto& p: fs::directory_iterator(inputfiles_directory))
        std::cout << "path: "<< p << '\n';
    return true;
}

bool TestFileSupport::RemoveTestFiles(std::string inputfiles_directory)
{
    //TODO: REMOVE cout in final version!!!
    errno = 0;
    std::error_code ec(errno, std::generic_category());
    std::cout << "Removed all test files from: "<< inputfiles_directory << std::endl;
    fs::remove_all(inputfiles_directory, ec);
    if(ec.value() != 0) {
        std::cout << "Error: " << ec.message() << std::endl;
        return false;
    }
    return true;
}
