#include "trade.h"

namespace march {

  int addTraderItem(Trade& t, TradingItem item, size_t quantity) {
    t.trader_items.push_back({static_cast<TradingItem>(item), quantity});
    return 0;
  }

  int addPlayerItem(Trade& t, TradingItem item, size_t quantity) {
    t.player_items.push_back({static_cast<TradingItem>(item), quantity});
    return 0;
  }

  int makeTrade(Army& a, Trader& t, Trade& tr) {

    // Fairness of a given trade will depend on the monetary value of the items being traded
    // find total monetary value of player items and trader items, and find if the difference is small enough or in trader's favour
  
    size_t trader_value{}, player_value{};

    for(size_t i = 0; i < tr.trader_items.size(); i++) {
      trader_value += itemPrices[tr.trader_items[i].item] * tr.trader_items[i].quantity;
    }
    std::cout << "Total value of Selected Trader items: " << trader_value << "\n";

    for(size_t i = 0; i < tr.player_items.size(); i++) {
      player_value += itemPrices[tr.player_items[i].item] * tr.player_items[i].quantity;
    }
    std::cout << "Total value of Player Trader items: " << player_value << "\n";

    int value_diff = trader_value - player_value;
    if(player_value > trader_value || value_diff < 3) {
      for(auto i: tr.trader_items) {
        a.items[i.item].quantity += i.quantity;
        t.items[i.item].quantity -= i.quantity;
      }
      for(auto i: tr.player_items) {
        a.items[i.item].quantity -= i.quantity;
        t.items[i.item].quantity += i.quantity;
      }
    } else {
      std::cout << "Trade Failed.\n";
    }
    return 0;
  }
}
