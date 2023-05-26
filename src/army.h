#pragma once

#include <random>
#include <fstream>

#include "status.h"
#include "supply_items.h"

namespace march {
struct Army {
  Army() {
    for(int i = 0; i < ITEM_SIZE; i++) {
      items[i].item = static_cast<TradingItem>(i);
      items[i].quantity = 0;
    }
  }
  void updateStats();
  void printSupplies();
  void generate(size_t size = 20);

  std::vector<int> ids;
  std::vector<std::string> names;
  std::vector<StatFlags> stats;
  std::vector<TradeElement> items{ITEM_SIZE};
  size_t supplies = 0;
  size_t alive = 0;
  size_t size;
};
}
