#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> ConvertStringToVector(std::string playerFrames);

std::string GetPlayerName(std::string playerFrames);

int CheckStatusForPlayer(std::string playerFrames);
