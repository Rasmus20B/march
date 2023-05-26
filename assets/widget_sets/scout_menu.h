#pragma once

#include "../../src/widget_set.h"
#include "../../src/widget.h"

class ScoutMenu : public march::WidgetSet {
public:
  ScoutMenu() {
    widgets = {
      march::Widget(config.screen_width / 3, config.screen_height / 3, config.screen_width / 3, (config.screen_height /3), 0x333333ff, 0xffffffff, march::WIDGET_NA, nullptr, 0),
      march::Widget(config.screen_width / 3, config.screen_height / 3, config.screen_width / 3, (config.screen_height / 3) * 2, 0x0000ffff, 0xffffffff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, []() {
            std::cout << "You Clicked the Navy Blue\n"; return 4;
            }, 1),
      march::Widget(config.screen_width / 3, config.screen_height / 3, config.screen_width / 3, (config.screen_height) - ((config.screen_height / 3) * 3), 0xff0000ff, 0xffffffff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, []() {
            std::cout << "You Clicked the Red\n"; return 5;
            }, 2),
    };
  }

};
