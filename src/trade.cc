#include "trade.h"
#include "supply_items.h"

namespace march {
  int addItemToTrade(Trade& t, TradingItem item, size_t quantity) {
    t.trader_items.push_back({static_cast<TradingItem>(item), quantity});
    return 0;
  }

  int makeTrade(Army& a, Trader& t, Trade& tr) {
    for(auto i: tr.trader_items) {
      a.items[i.item].quantity += i.quantity;
      t.items[i.item].quantity -= i.quantity;
    }

    return 0;
  }
}
