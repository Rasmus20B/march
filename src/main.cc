#include "area.h"
#include "march.h"
#include "trade.h"

int main() {
  
  size_t day = 1;
  size_t stage = 0;
  march::Army a{};
  a.generate();
  march::Area area{"battelfield", march::AREA_ROAD, std::nullopt};

  while(a.alive > 0) {
    if(stage % 5 == 0) {
      march::Trader t;
      area.name = "town";
      area.type = march::AREA_TOWN;
      area.trader = t;
      t.items.push_back({march::TRADING_FOOD, 5});
      t.items.push_back({march::TRADING_WEAPONS, 3});
      t.items.push_back({march::TRADING_MERCS, 8});
    } else {
      area.name = "wilderness";
      area.type = march::AREA_ROAD;
      area.trader = std::nullopt;
    }
    std::cout << "Day " << day << "\n=====================\n";
    std::cout << "Location: " << area.name << "\n=====================\n";
menu:
    int choice = march::gameMenu(area);
    switch(choice) {
      case 1:
        stage++;
        break;
      case 2:
        march::selectScout(a);
        break;
      case 3:
        if(area.type == march::AREA_TOWN) {
          march::selectTrade(a);
          break;   
        }
      default:
        std::cout << "Invalid choice\n";
        goto menu;
    }
    a.updateStats();
    a.printSupplies();
    std::cout << "\n";
    day++;
  }

  return 1;

}
