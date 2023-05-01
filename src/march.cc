#include "march.h"
#include "SDL_error.h"
#include "gui.h"

namespace march {

int gameloop() {
  size_t day = 1;
  size_t stage = 1;
  size_t prevStage = stage;

  Army a{};
  a.generate(20);


  Gui gui;
  gui.init();
  gui.main_loop();

  return 0;
}

int gameloop_text() {
  size_t day = 1;
  size_t stage = 1;
  size_t prevStage = stage;
  Army a{};


  a.generate();
  march::Area area{NATION_BABYLONIA, AREA_ROAD, std::nullopt};
  while(a.alive > 0) {
    if(stage % 5 == 0 && stage != prevStage) {
      Trader t;
      area.nation = static_cast<AreaNation>(area.nation + 1);
      area.type = AREA_TOWN;
      area.trader = t;
    } else if (stage != prevStage){
      area.type = AREA_ROAD;
      area.trader = std::nullopt;
    }
    prevStage = stage;
    displayDayAndLocation(day, area.nation);
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
        break;
      case 9:
        return 0;
      default:
        std::cout << choice << " is an Invalid choice\n";
        goto menu;
    }
    a.updateStats();
    std::cout << "\n";
    day++;
  }

  return 0;
}
}
