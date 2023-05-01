#pragma once

#include "widget_set.h"

namespace march {
struct Screen {
  /* Stores a collection of widgetSets */
  Screen(const WidgetSet set) {
    sets.push_back(set);
  }

  Screen() = default;
  Screen(const Screen&) = delete;

  void store();
  void switch_to(const size_t id);
  void remove(const size_t id);
  std::vector<WidgetSet> sets;
  std::vector<size_t> ids;
};
}
