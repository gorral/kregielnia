#include "TenPinBowling.hpp"
#include <stdexcept>

TenPinBowling::TenPinBowling(std::string const & name, std::vector<Game> const & game,
                             std::string const & in_dir_name, std::string const & out_file_name)
    :name_(name)
    ,games_(game)
    ,in_dir_name_(in_dir_name)
    ,out_file_name_(out_file_name)
{}

TenPinBowling::~TenPinBowling()
{}

bool TenPinBowling::loadInputFiles()
{
    fs::path directoryPath = fs::current_path() /= TenPinBowling::in_dir_name_;
    std::string filePath;
    std::vector<Player> game{};
    std::string playerName{};
    std::vector<int> playerFrames{};
    int score = 0;
    enum Status status{Status::NotStarted};

    if (not fs::is_directory(directoryPath) or fs::is_empty(directoryPath)) {
        throw std::logic_error("There is lack of input files!");
    }
    for (auto & p : fs::directory_iterator(directoryPath)) {

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
