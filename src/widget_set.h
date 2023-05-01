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

class TitleMenu : public WidgetSet {
public:
  TitleMenu() {
    widgets = {
      Widget(config.screen_width, config.screen_height, 0, 0, 0xFFC420ff, 0x181818ff, WIDGET_NA, nullptr, 0),
      Widget(280, 100, 40, 350, 0x127f81ff, 0x181818ff, WIDGET_CLICKABLE | WIDGET_HOVER, [](){ return 1; }, 1),
      Widget(280, 100, 40 + 280, 350, 0xffff00ff, 0xffffffff, WIDGET_CLICKABLE | WIDGET_HOVER, []() { return 2; }, 2)
    };
  }
};


class MainHUD : public WidgetSet {
public:
  MainHUD() {
    widgets = {
      Widget(config.screen_width, config.screen_height, 0, 0, 0xffffffff, 0xffffffff, WIDGET_NA, nullptr, 0),
      Widget(426, 200, 0, config.screen_height - 160, 0xffff00ff, 0xffffffff, WIDGET_CLICKABLE, [](){
            std::cout << "You clicked the Yellow\n"; return 0;
            }, 1 ),
      Widget(214, 160, 426, config.screen_height - 320, 0xff00ffff, 0xffffffff, WIDGET_CLICKABLE, []() {
            std::cout << "You clicked the Pink\n"; return 0;
            }, 2 ),
      Widget(214, 160, 426, config.screen_height - 480, 0x00ffffff, 0xffffffff, WIDGET_CLICKABLE, []() {
            std::cout << "You clicked the Cyan\n"; return 0;
            return 0;
            }, 3),
      Widget(108, 160, 640 - 107, config.screen_height - 160, 0xff0000ff, 0xffffffff, WIDGET_CLICKABLE, []() {
            std::cout << "You Clicked the Red\n";
            std::cout << "Quitting Game!\n"; return 1;
            }, 4),
      Widget(108, 160, 640 - 214, config.screen_height - 160, 0x0000ffff, 0xffffffff, WIDGET_CLICKABLE, []() {
            std::cout << "You Clicked the Navy Blue\n"; return 0;
            }, 5)
    };
  }
};
}
