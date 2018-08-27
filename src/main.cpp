#include <iostream>
#include "Kregielnia.hpp"
#include "Helper.hpp"

int main()
{
    Helper::CreateTestFiles();
    Helper::RemoveTestFiles();

    std::cout << "Kregielnia!" << std::endl;
    return 0;
}
