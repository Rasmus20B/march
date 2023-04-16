#pragma once

#include <random>

#include "status.h"

namespace march {
struct Army {
  void updateStats();
  void printSupplies();
  void generate(size_t size = 20);

  std::vector<int> ids;
  std::vector<std::string> names;
  std::vector<StatFlags> stats;
  size_t alive = 0;
  size_t supplies = 0;
  size_t size;
};
}
