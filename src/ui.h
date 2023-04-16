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

// Main game menu. May display different options depending on area/event
int gameMenu(Area& a);

// displays the menu to select the scouts that will be senton mission
void selectScout(Army& a);

// returns the scouts that have been chosen to perform mission
std::vector<int> scoutMenu();

// Displays the result of a given scouting mission
void scoutResult(march::Army& a, MissionReport &r);

// What displays when the user selects to trade 
void selectTrade(Army& a, Trader& t);

// As it says
void displayTraderItems(Trader& t);

// Allow the use to select the items and quantites for trade
void selectItemForTrade(Trade& t);
}
