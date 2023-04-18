#include "ui.h"
#include "trade.h"

namespace march {
int selectLevel(int l) {
  return 1;
}

int gameMenu(Area& a) {
  std::cout << "What would you like to do?\n";
  std::cout << "(1) March!\n";
  std::cout << "(2) Scout. \n";
  if(a.type == AREA_TOWN) {
    std::cout << "(3) Trade/Talk to locals.\n";
  }
  std::cout << "(9) Quit...\n";

  int choice;
  std::cin >> choice;
  return choice;
}

void displayDayAndLocation(int day, std::string_view location) {
  std::cout << "\n=====================\n";
  std::cout << "Day " << day << "\n=====================\n";
  std::cout << "Location: " << location << "\n=====================\n";
}

void selectScout(Army& a) {
  std::vector<int> s = march::scoutMenu();
  march::MissionReport r = march::scout(s);
  march::scoutResult(a, r);
}

std::vector<int> scoutMenu() {
  std::vector<int> solds;
  std::string line;
  std::cout << "Please select the soldiers you want to send: ";
  std::cin.ignore();
  std::getline(std::cin, line);
  std::stringstream ss(line);
  std::copy(std::istream_iterator<int>(ss), std::istream_iterator<int>(), std::back_inserter(solds));
  return solds;
}

void scoutResult(Army& a, MissionReport& m) {
  switch(m.res) {
    case 1:
      std::cout << "scout successful, found food and stuff\n";
      a.items[ITEM_FOOD].quantity += m.supplies;
      break;
    case 2:
      std::cout << "found some food, but lost soldiers: \n";
      for(size_t i = 0; i < m.dead.size(); i++) {
        std::cout << "updating: " << m.dead.at(i) << "\n";
        a.stats[m.dead.at(i)].dead();
        a.alive--;
      }
      a.items[ITEM_FOOD].quantity += m.supplies;
      break;
    case 3:
      std::cout << "the scouting party never returned\n";
      for(size_t i = 0; i < m.dead.size(); i++) {
        std::cout << "updating: " << m.dead.at(i) << "\n";
        a.stats[m.dead.at(i)].dead();
        a.alive--;
      }
      break;
    case 4:
      std::cout << "the scouting party returned empty handed\n";
      break;
  }
}

void displayTraderItems(Trader& t) {
  for(unsigned i = 0; i < t.items.size(); i++) {
    std::cout << "(" << i << ") " <<itemNames[t.items.at(i).item] << " : " << t.items.at(i).quantity << " @" << itemPrices[t.items.at(i).item] << " each\n";
  }
}
void displayPlayerItems(Army& a) {
  for(unsigned i = 0; i < a.items.size(); i++) {
    std::cout << "(" << i << ") " << itemNames[a.items.at(i).item] << " : " << a.items.at(i).quantity << " @" << itemPrices[a.items.at(i).item] << " each\n";
  }
}

bool tradeMenu() {
  return true;
}
void selectTrade(Army& a, Trader& t) {
  std::cout << "The town trader has:\n";
  displayTraderItems(t);

  Trade tr;

  size_t choice = 0;
  bool finish = false;
  while(!finish) {
    std::cout << "Please choose Trader Items to add to trade.\n(9) Next\n";
    std::cin >> choice;
    if(choice == 9) {
      break;
    } else if(choice > t.items.size()) {
      std::cout << "Invalid Item Choice!\n";
      continue;
    } else {
      std::cout << "Please select quantity of " << itemNames[t.items[choice].item] << "\n";
      size_t quant{};
      std::cin >> quant;
      if(quant > t.items[choice].quantity) {
        std::cout << "Invalid quantity!\n";
        continue;
      }
      addTraderItem(tr, t.items[choice].item, quant);
    }
  }
  finish = false;

  displayPlayerItems(a);
  while(!finish) {
    std::cout << "Please choose your Items to add to trade.\n(9) To Finish Trade\n";
    std::cin >> choice;
    if(choice == 9) {
      break;
    } else if(choice > t.items.size()) {
      std::cout << "Invalid Item Choice!\n";
      continue;
    } else {
      std::cout << "Please Select quantity of " << itemNames[t.items[choice].item] << "\n";
      size_t quant{};
      std::cin >> quant;
      if(quant > t.items[choice].quantity) {
        std::cout << "Invalid Quantity\n";
        continue;
      }
      addPlayerItem(tr, t.items[choice].item, quant);
    }
  }
  makeTrade(a, t, tr);
  return;
}


void selectItemForTrade(Trade& t) {
  return;
}
}
