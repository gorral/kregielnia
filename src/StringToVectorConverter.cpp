#include "StringToVectorConverter.hpp"

int lambda(char c)
{
    if(c == '-'){
        return 0;
    }else if(std::isdigit(c) ){
        return c - 48;
    }else if(c == 'X') {
        return 10;
    }
    return 0;
}

int SumLastTwoThrows(std::string const & playerFrames)
{
    return lambda(*playerFrames.rbegin()) + lambda(*playerFrames.rbegin()+1);
}

int CountFramesInGame(std::string const & playerFrames)
{
    return std::count(std::begin(playerFrames), std::end(playerFrames), '|');
}

int CountThrowsInLastFrame(std::string const & playerFrames)
{
    return std::distance(std::find(std::rbegin(playerFrames), std::rend(playerFrames), '|'), std::rbegin(playerFrames));
}

char CompliteSpare(char firstThrow)
{
    return *std::to_string( 10 - (static_cast<int>(firstThrow) - 48) ).c_str();
}

std::string ExtractPointsFromString(std::string const & playerFrames)
{
    std::string str = playerFrames;
    auto const pos=playerFrames.find_last_of(':');
    if(pos != std::string::npos)
        str.erase(str.begin(), str.begin()+pos);

    str.erase(std::remove(str.begin(), str.end(), '|'),str.end());

    for(int i = 0; i < str.length(); i ++)
        if(str[i] == '/')
            str[i] = CompliteSpare(str[i-1]);
    return str;
}

std::vector<int> ConvertStringToVector(std::string const & playerFrames)
{
    std::string str = ExtractPointsFromString(playerFrames);

    std::vector<int> vec;

    std::transform(str.begin(), str.end(),
                   std::back_inserter(vec),
                   [vec](char c) {return lambda(c);});
    return vec;
}

std::string GetPlayerName(std::string const &playerFrames)
{

    auto const pos=playerFrames.find_last_of(':');

    std::string name;
    std::copy(playerFrames.begin(),
              playerFrames.begin() + pos,
              std::back_inserter(name));
    return name;
}

Status CheckStatusForPlayer(std::string const & playerFrames)
{
    if(playerFrames.length() > 0){
        if(CountFramesInGame(playerFrames) == 9 && CountThrowsInLastFrame(playerFrames) == -2 && SumLastTwoThrows(playerFrames) < 10)
                return Status::Finished;

        if(CountFramesInGame(playerFrames) == 11 &&
            ((CountThrowsInLastFrame(playerFrames) == -1 && *playerFrames.rbegin() != 'X') ||
                    CountThrowsInLastFrame(playerFrames) == -2))
                return Status::Finished;

        return Status::InProgress;
    }

    return Status::NotStarted;
}
