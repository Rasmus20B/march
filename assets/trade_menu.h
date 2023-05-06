#pragma once

#include "../src/widget_set.h"
#include "../src/widget.h"

class TradeMenu : public march::WidgetSet {
public:
  TradeMenu() {
    widgets = {
      march::Widget((config.screen_width / 3 * 2), ((config.screen_height / 3) * 2), ((config.screen_width / 3) * 2), config.screen_height - ((config.screen_height / 3) * 2), 0xff0000ff, 0xffffffff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, []() {
            std::cout << "You Clicked the Gray\n"; return 4;
            }, 2),
      march::Widget(config.screen_width / 3, config.screen_height / 3, config.screen_width / 3, config.screen_height - (config.screen_height / 3), 0x333333ff, 0xffffffff, march::WIDGET_NA, nullptr, 0),
      // march::Widget((config.screen_width / 2) / 2, 160, (config.screen_width / 2), config.screen_height - 320, 0x0000ffff, 0xffffffff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, []() {
            // std::cout << " Clicked the Navy Blue\n"; return 3;
            // }, 1),
    };
  }
};



