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


class ScoutMenu : public WidgetSet {
public:
  ScoutMenu() {
    widgets = {
      Widget(213, 160, 213, config.screen_height - 160, 0x333333ff, 0xffffffff, WIDGET_NA, nullptr, 0),
      Widget(213, 160, 107, config.screen_height - 320, 0x0000ffff, 0xffffffff, WIDGET_CLICKABLE | WIDGET_HOVER, []() {
            std::cout << "You Clicked the Navy Blue\n"; return 4;
            }, 1),
      Widget(213, 160, 213, config.screen_height - 320, 0xff0000ff, 0xffffffff, WIDGET_CLICKABLE | WIDGET_HOVER, []() {
            std::cout << "You Clicked the Navy Blue\n"; return 5;
            }, 2),
    };
  }

};


}
