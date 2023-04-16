#include "ui.h"

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
      a.supplies += m.supplies;
      break;
    case 2:
      std::cout << "found some food, but lost soldiers: \n";
      for(size_t i = 0; i < m.dead.size(); i++) {
        std::cout << "updating: " << m.dead.at(i) << "\n";
        a.stats[m.dead.at(i)].dead();
        a.alive--;
      }
      a.supplies += m.supplies;
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
bool tradeMenu() {
  return true;
}
void selectTrade(Army& a, Trader& t) {
  std::cout << "The town trader has:\n";
  displayTraderItems(t);
  return;
}

void displayTraderItems(Trader& t) {
  for(unsigned i = 0; i < t.items.size(); i++) {
    std::cout << itemNames[t.items.at(i).item] << " : " << t.items.at(i).quantity << "\n";
  }
}

void selectItemForTrade(Trade& t) {
  return;
}
}
