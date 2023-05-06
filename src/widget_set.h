#pragma once

#include <iostream>
#include <vector>

#include "widget.h"
#include "config.h"

namespace march {
class WidgetSet {
public:
  /* Used to store a collection of widgets that can be swapped out by a window for another set of widgets easily. */
  WidgetSet() = default;
  ~WidgetSet() = default;
  void store(const Widget& w);
  void remove(const size_t id);

public:
  std::vector<Widget> widgets;
  std::vector<size_t> ids;
};




}
