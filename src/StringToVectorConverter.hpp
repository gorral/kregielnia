#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> ConvertStringToVector(std::string const & playerFrames);

std::string GetPlayerName(std::string const &playerFrames);

int CheckStatusForPlayer(const std::string &playerFrames);
