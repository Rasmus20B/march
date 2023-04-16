#pragma once

#include <vector>
#include <iostream>
#include <cstdarg>
#include <sstream>

#include "area.h"
#include "army.h"
#include "march.h"
#include "scout.h"
#include "trade.h"

namespace march {

int selectLevel(int l);
int gameMenu(Area& a);
void selectScout(Army& a);
std::vector<int> scoutMenu();

void scoutResult(march::Army& a, MissionReport &r);

// What displays when the user selects to trade 
void selectTrade(Army& a);

// As it says
void displayTraderItems(Trader& t);

// Allow the use to select the items and quantites for trade
void selectItemForTrade(Trade& t);
}
