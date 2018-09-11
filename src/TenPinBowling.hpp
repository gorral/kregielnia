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
public:
    TenPinBowling(std::string const & name, std::vector<Game> const & game);
    ~TenPinBowling();
    bool loadInputFiles(std::string const & path);
    int gamesCntr();
};
