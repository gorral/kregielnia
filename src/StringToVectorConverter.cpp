#include "StringToVectorConverter.hpp"

int lambda(char c){
    if(c == '-'){
        return 0;
    }else if(std::isdigit(c) ){
        return c - 48;
    }else if(c == 'X') {
        return 10;
    }
    return 0;
}

std::string ExtractPointsFromString(std::string playerFrames){
    if(playerFrames.find(':') != std::string::npos)
        playerFrames.erase(playerFrames.begin(), std::find(std::begin(playerFrames), std::end(playerFrames), (':'))+1);

    playerFrames.erase(std::remove(playerFrames.begin(), playerFrames.end(), '|'),playerFrames.end());

    for(int i = 0; i < playerFrames.length(); i ++)
        if(playerFrames[i] == '/')
            playerFrames[i] = *std::to_string( 10 - (static_cast<int>(playerFrames[i-1]) - 48) ).c_str();
    return playerFrames;
}

std::vector<int> ConvertStringToVector(std::string playerFrames){

    playerFrames = ExtractPointsFromString(playerFrames);

    std::vector<int> vec;

    std::transform(playerFrames.begin(), playerFrames.end(),
                   std::back_inserter(vec),
                   [vec](char c) {return lambda(c);});
    return vec;
}

std::string GetPlayerName(std::string playerFrames){

    std::string name;
    std::copy(playerFrames.begin(),
              std::find(std::begin(playerFrames), std::end(playerFrames), (':')),
              std::back_inserter(name));
    return name;
}
