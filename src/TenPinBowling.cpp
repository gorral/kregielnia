#include "TenPinBowling.hpp"
#include <stdexcept>

TenPinBowling::TenPinBowling(std::string const & name, std::vector<Game> const & game,
                             fs::path const & input_dir_path, fs::path const & output_file_path)
    :name_(name)
    ,games_(game)
    ,input_dir_path_(input_dir_path)
    ,output_file_path_(output_file_path)
{}

TenPinBowling::~TenPinBowling()
{}

bool TenPinBowling::loadInputFiles()
{
    std::string filePath;
    std::vector<Player> game{};
    std::string playerName{};
    std::vector<int> playerFrames{};
    int score = 0;
    enum Status status{Status::NotStarted};

    if (not fs::is_directory(input_dir_path_) or fs::is_empty(input_dir_path_)) {
        throw std::logic_error("There is lack of input files!");
    }
    for (auto & p : fs::directory_iterator(input_dir_path_)) {

        filePath = p.path();
        std::ifstream fileStream(filePath);
        for (std::string singleLine; std::getline(fileStream, singleLine); ) {
            //TODO::cout only for debug remove in release version!
            std::cout <<singleLine<<std::endl;

            auto singlePlayer = std::make_tuple(playerName, playerFrames, score, status);
            game.push_back(singlePlayer);
        }
        games_.push_back(game);
    }
    return true;
}

int TenPinBowling::gamesCntr()
{
    return games_.size();
}
