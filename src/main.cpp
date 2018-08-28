#include <iostream>
#include "Kregielnia.hpp"
#include "TestFileSupport.hpp"

int main()
{
    const std::string inputfiles_directory = "test_files";
    TestFileSupport::CreateTestFiles(inputfiles_directory);
    TestFileSupport::RemoveTestFiles(inputfiles_directory);

    std::cout << "Kregielnia!" << std::endl;
    return 0;
}
