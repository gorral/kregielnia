#include "TenPinBowling.hpp"

TenPinBowling::TenPinBowling(std::string const & name, std::vector<Game> const & game)
    :name_(name)
    ,games_(game)
{}

TenPinBowling::~TenPinBowling()
{}

std::string readFile(std::string & path)
{
    std::ifstream ifsstream(path);
    std::string fileContent( (std::istreambuf_iterator<char>(ifsstream) ),
                               (std::istreambuf_iterator<char>()    ) );
    return fileContent;
}

bool TenPinBowling::loadInputFiles(std::string const &path)
{
    //TODO: add error handling
    std::string filePath;
      for (auto & p : fs::directory_iterator(path)) {
        filePath = p.path();
        games_.push_back(std::make_tuple(readFile(filePath)));
      }

    return true;
}

int TenPinBowling::gamesCntr()
{
    return games_.size();
}
