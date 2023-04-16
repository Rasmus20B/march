#pragma once

#include <vector>
#include <random>
#include <string_view>

#include "army.h"

namespace march { 
enum TradingItem {
  ITEM_WEAPONS,
  ITEM_FOOD,
  ITEM_MERCS,
  ITEM_SIZE
};

constexpr std::array<std::string_view, ITEM_SIZE> itemNames = {
  "WEAPONS",
  "FOOD",
  "MERCENARIES"
};

struct TradeElement {
  TradingItem item;
  size_t quantity;
};

struct Trade {
  std::vector<TradeElement> player_items;
  std::vector<TradeElement> trader_items;
};


struct Trader {
  Trader() noexcept {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> quantRange(0, 10);
    for(int i = 0; i < ITEM_SIZE; i++) {
      items.push_back({static_cast<TradingItem>(i), static_cast<size_t>(quantRange(gen))});
    }
  }
  std::vector<TradeElement> items;
};

int trade(Army& a, Trader& t);
int addItemToTrade();
int makeTrade(Army& a, Trader& t, Trade& tr);
}
