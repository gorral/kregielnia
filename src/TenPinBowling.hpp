#pragma once
#include <tuple>
#include <vector>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

enum class Status {
    NotStarted,
    InProgress,
    Finished
};

/// \brief Player tuple fields:
/// std::string         - playerName
/// std::vector<int>    - playerFrames
/// int                 - score
/// Status              - status
using Player = std::tuple<std::string, std::vector<int>, int, Status>;
using Game = std::vector<Player>;

class TenPinBowling
{
private:
    std::string name_;
    std::vector<Game> games_;
    std::string in_dir_name_;
    std::string out_file_name_;
public:
    TenPinBowling(std::string const & name, std::vector<Game> const & game,
                  std::string const & in_dir_name, std::string const & out_file_name);
    ~TenPinBowling();
    bool loadInputFiles();
    int gamesCntr();
};
