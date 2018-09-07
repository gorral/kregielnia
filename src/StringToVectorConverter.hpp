#pragma once

#include <string>
#include <vector>
#include <algorithm>

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

std::vector<int> ConvertStringToVector(std::string str){

    str.erase(std::remove(str.begin(), str.end(), '|'), str.end());

    for(int i = 0; i < str.length(); i ++)
        if(str[i] == '/'){
            str[i] = *std::to_string( 10 - (static_cast<int>(str[i-1]) - 48) ).c_str();
        }
    std::vector<int> vec;

    std::transform(str.begin(),
                   str.end(),
                   std::back_inserter(vec),
                   [vec](char c) {
                    return lambda(c);
                     });

    return vec;
}
