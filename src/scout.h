#pragma once

#include <iostream>
#include <random>
#include <iterator>
#include <random>
#include <algorithm>

#include "army.h"

namespace march {
struct MissionReport {
  std::vector<int>& sent;
  std::vector<int> dead;
  size_t supplies;
  uint8_t res;
};

MissionReport scout(std::vector<int>& s);
}
