#pragma once

#include "../src/widget_set.h"
#include "../src/widget.h"

class TitleMenu : public march::WidgetSet {
public:
  TitleMenu() {
    widgets = {
      march::Widget(config.screen_width, config.screen_height, 0, 0, 0xFFC420ff, 0x181818ff, march::WIDGET_NA, nullptr, 0),
      march::Widget(280, 100, 40, 350, 0x127f81ff, 0x181818ff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, [](){ return 1; }, 1),
      march::Widget(280, 100, 40 + 280, 350, 0xffff00ff, 0xffffffff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, []() { return 2; }, 2)
    };
  }
};
