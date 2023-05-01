#include "army.h"
#include <iterator>

namespace march {
void Army::generate(size_t sz) {
  ids.resize(sz);
  stats.resize(sz);
  alive = size;

  std::random_device rd;
  std::mt19937 generator(rd());

  std::ifstream f("../assets/names.txt");
  std::vector<std::string> list{};
  std::string name;

  while(std::getline(f, name)) {
    list.push_back((name));
  }

  std::uniform_int_distribution<int> distr(1, list.size() - 1);
  names.resize(sz);
  for(auto &i : names) {
    i = list[distr(generator)];
  }
  std::iota(ids.begin(), ids.end(), 0);
}

void Army::updateStats() {
  for(auto &i : stats) {
    i.printFlags();
  }
}

void Army::printSupplies() {
  std::cout << "Army Supplies:\n=====================\n";
  for(auto i : items) {
    std::cout << itemNames[i.item] << " : " << i.quantity << "\n";
  }
  std::cout << "=====================\n";
}
}
