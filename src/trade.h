#pragma once

#include <vector>

#include "army.h"

namespace march { 
enum TradingItem {
  TRADING_WEAPONS,
  TRADING_FOOD,
  TRADING_MERCS,
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
  std::vector<TradeElement> items;
};

int trade(Army& a, Trader& t);
int makeTrade(Army& a, Trader& t, Trade& tr);
int addToTrade();
}
