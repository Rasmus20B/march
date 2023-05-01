#pragma once

#include <vector>

#include "widget.h"

namespace march {
struct WidgetSet {

  /* Used to store a collection of widgets that can be swapped out by a window for another set of widgets easily. */
  void store(const Widget& w);
  void remove(const size_t id);
  std::vector<Widget> widgets;
  std::vector<size_t> ids;
};
}
