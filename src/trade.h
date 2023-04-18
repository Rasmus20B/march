#pragma once

#include <vector>
#include <random>
#include <string_view>
#include <algorithm>

#include "supply_items.h"
#include "army.h"

namespace march { 

struct Trade {
  std::vector<TradeElement> player_items;
  std::vector<TradeElement> trader_items;
};

struct Trader {
  Trader() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> quantRange(0, 10);
    for(int i = 0; i < ITEM_SIZE; i++) {
      items.push_back({static_cast<TradingItem>(i), static_cast<size_t>(quantRange(gen))});
    }
  }
  std::vector<TradeElement> items;
};

int addTraderItem(Trade& t, TradingItem item, size_t quantity);
int addPlayerItem(Trade& t, TradingItem item, size_t quantity);
int makeTrade(Army& a, Trader& t, Trade& tr);
}
