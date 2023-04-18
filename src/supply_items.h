#pragma once

#include <array>
#include <string_view>

namespace march { 
enum TradingItem {
  ITEM_WEAPONS,
  ITEM_FOOD,
  ITEM_MERCS,
  ITEM_MONEY,
  ITEM_SIZE
};

constexpr std::array<int, ITEM_SIZE> itemPrices = {
  2, 3, 4, 5
};

constexpr std::array<std::string_view, ITEM_SIZE> itemNames = {
  "WEAPONS",
  "FOOD",
  "MERCENARIES",
  "MONEY"
};
struct TradeElement {
  TradingItem item;
  size_t quantity;
};
}
