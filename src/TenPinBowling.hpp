#pragma once
#include <tuple>
#include <vector>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

using Game = std::tuple<std::string>;

class TenPinBowling
{
private:
    std::string name_;
    std::vector<Game> games_;
public:
    TenPinBowling(std::string const & name);
    ~TenPinBowling();
    bool loadInputFiles(std::string const & path);
    int gamesCntr();
};
