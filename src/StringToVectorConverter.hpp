#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "TenPinBowling.hpp"

std::vector<int> ConvertStringToVector(std::string const & playerFrames);

std::string GetPlayerName(std::string const &playerFrames);

Status CheckStatusForPlayer(const std::string &playerFrames);
