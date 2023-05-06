#pragma once

#include "../src/widget_set.h"
#include "../src/widget.h"

class ScoutMenu : public march::WidgetSet {
public:
  ScoutMenu() {
    widgets = {
      march::Widget(213, 160, 213, config.screen_height - 160, 0x333333ff, 0xffffffff, march::WIDGET_NA, nullptr, 0),
      march::Widget(213, 160, 107, config.screen_height - 320, 0x0000ffff, 0xffffffff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, []() {
            std::cout << "You Clicked the Navy Blue\n"; return 4;
            }, 1),
      march::Widget(213, 160, 213, config.screen_height - 320, 0xff0000ff, 0xffffffff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, []() {
            std::cout << "You Clicked the Navy Blue\n"; return 5;
            }, 2),
    };
  }

};
