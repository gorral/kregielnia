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
    fs::path input_dir_path_;
    fs::path output_file_path_;
public:
    TenPinBowling(std::string const & name, std::vector<Game> const & game,
                  fs::path const & input_dir_path, fs::path const & output_file_path);
    ~TenPinBowling();
    bool loadInputFiles();
    int gamesCntr();
};
