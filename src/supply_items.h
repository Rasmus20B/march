#pragma once

#include <array>
#include <string_view>

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
}
