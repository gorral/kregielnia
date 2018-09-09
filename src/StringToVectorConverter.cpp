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

std::string ExtractPointsFromString(std::string playerGame){
    if(playerGame.find(':') != std::string::npos)
        playerGame.erase(playerGame.begin(), std::find(std::begin(playerGame), std::end(playerGame), (':'))+1);

    playerGame.erase(std::remove(playerGame.begin(), playerGame.end(), '|'),playerGame.end());

    for(int i = 0; i < playerGame.length(); i ++)
        if(playerGame[i] == '/')
            playerGame[i] = *std::to_string( 10 - (static_cast<int>(playerGame[i-1]) - 48) ).c_str();
    return playerGame;
}

std::vector<int> ConvertStringToVector(std::string playerGame){

    playerGame = ExtractPointsFromString(playerGame);

    std::vector<int> vec;

    std::transform(playerGame.begin(), playerGame.end(),
                   std::back_inserter(vec),
                   [vec](char c) {return lambda(c);});
    return vec;
}

std::string GetPlayerName(std::string playerGame){

    std::string name;
    std::copy(playerGame.begin(),
              std::find(std::begin(playerGame), std::end(playerGame), (':')),
              std::back_inserter(name));
    return name;
}
