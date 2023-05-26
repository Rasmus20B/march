#pragma once

#include <numbers>

namespace march {
enum WidgetReturnType {
  WIDGET_RET_NA = 0,
  WIDGET_RET_SWITCH_SCR = 2,
  WIDGET_RET_TRADE_ADD_PL = 4,
  WIDGET_RET_TRADE_ADD_TR = 8,
  WIDGET_RET_EXIT = 16,
};
struct WidgetReturn {
  WidgetReturnType t;
  size_t val;
};
}
