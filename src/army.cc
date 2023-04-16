#include "army.h"

namespace march {
void Army::generate(size_t size) {
  ids.resize(size);
  stats.resize(size);
  alive = size;
  std::iota(ids.begin(), ids.end(), 0);
}

void Army::updateStats() {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distr(1, STATUS_SIZE - 1);
  for(auto &i : stats) {
    i.printFlags();
  }
}

void Army::printSupplies() {
  std::cout << "The Army currently has " << supplies << " supplies";
}
}
