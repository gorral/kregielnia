#include "TenPinBowling.hpp"

TenPinBowling::TenPinBowling(std::string const & name)
    :name_(name)
    ,games_()
{}

TenPinBowling::~TenPinBowling()
{}

std::string readFile(fs::directory_iterator & iter)
{
    std::stringstream stream_path;

    stream_path << iter->path().c_str();

    std::ifstream ifsstream(stream_path.str());
    std::string fileContent( (std::istreambuf_iterator<char>(ifsstream) ),
                               (std::istreambuf_iterator<char>()    ) );

    return fileContent;
}

bool TenPinBowling::loadInputFiles(std::string const &path)
{
    fs::directory_iterator iter(path), end;

    for(;iter != end; iter++) {
        //TODO:: cout only for debug
        std::cout << readFile(iter);
        games_.push_back(std::make_tuple(readFile(iter)));
    }
    return true;
}

int TenPinBowling::gamesCntr()
{
    return games_.size();
}
