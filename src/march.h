#pragma once

#include <bitset>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <random>
#include <limits>

#include "ui_text.h"
#include "gui.h"
#include "army.h"
#include "scout.h"
#include "trade.h"
#include "area.h"
#include "day.h"

namespace march {
  int gameloop_text();
  int gameloop();
}
