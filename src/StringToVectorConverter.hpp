#ifndef STRINGTOVECTORCONVERTER_H
#define STRINGTOVECTORCONVERTER_H

#include <string>
#include <vector>
#include <algorithm>

std::vector<int> ConvertStringToVector(std::string str){

    str.erase(std::remove(str.begin(), str.end(), '|'), str.end());

    for(int i = 0; i < str.length(); i ++)
        if(str[i] == '/')
            str[i] = (10-(str[i-1]-48))+48;

    std::vector<int> vec;

    std::transform(str.begin(),
                   str.end(),
                   std::back_inserter(vec),
                   [vec](char c) {
                    if(c == '-'){
                        return 0;
                    }else if(c >= 48 && c<= 57 ){
                        return c - 48;
                    }else if(c == 'X') {
                        return 10;
                    }
                    return 0;
                     });

    return vec;
}

#endif // STRINGTOVECTORCONVERTER_H
