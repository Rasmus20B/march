#include "march.h"

namespace march {

int gameloop() {
  size_t day = 1;
  size_t stage = 1;
  size_t prevStage = stage;
  Army a{};
  a.generate();
  march::Area area{"battlefield", AREA_ROAD, std::nullopt};
  while(a.alive > 0) {
    if(stage % 5 == 0 && stage != prevStage) {
      Trader t;
      area.name = "Town";
      area.type = AREA_TOWN;
      area.trader = t;
    } else if (stage != prevStage){
      area.name = "Wilderness";
      area.type = AREA_ROAD;
      area.trader = std::nullopt;
    }
    prevStage = stage;
    displayDayAndLocation(day, area.name);
    a.printSupplies();
menu:
    int choice = gameMenu(area);
    switch(choice) {
      case 1:
        stage++;
        break;
      case 2:
        selectScout(a);
        break;
      case 3:
        if(area.type == AREA_TOWN) {
          if(stage == prevStage) {
            selectTrade(a, *area.trader);
          }
          break;
        }
      case 9:
        return 0;
      default:
        std::cout << "Invalid choice\n";
        goto menu;
    }
    a.updateStats();
    std::cout << "\n";
    day++;
  }

  return 0;
}
}
