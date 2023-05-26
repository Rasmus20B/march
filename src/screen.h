#pragma once

#include "widget_set.h"

namespace march {

class Screen {
public:
  /* Stores a collection of widgetSets */
  Screen(const std::vector<WidgetSet>& set) {
    sets = std::move(set);
  }
  Screen() = default;
  Screen(const Screen&) = delete;

  void store(const WidgetSet& set);
  void switch_to(const size_t id);
  void remove(const size_t id);

  std::vector<WidgetSet> sets;
  std::vector<size_t> ids;
  size_t active_set;
  size_t size;
};
}
