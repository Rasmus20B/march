#pragma once

#include "../src/widget_set.h"
#include "../src/widget.h"
#include "SDL_ttf.h"

class TitleMenu : public march::WidgetSet {
public:
  TitleMenu() {
    widgets = {
      march::Widget(config.screen_width, config.screen_height, 0, 0, 0xFFC420ff, 0x181818ff, march::WIDGET_NA, nullptr, 0),
      march::Widget((config.screen_width) , config.screen_height / 2, 0, config.screen_height / 5, 0x000000ff, 0x000000ff, march::WIDGET_TEXT, nullptr, "March", TTF_OpenFont("../assets/fonts/OpenSans-Semibold.ttf", 240), 0xffffffff, 1),
      march::Widget(config.screen_width / 3, config.screen_height / 5, config.screen_width / 8, 350, 0x127f81ff, 0x181818ff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, [](){ return 1; }, 2),
      march::Widget(config.screen_width / 3, config.screen_height / 5, config.screen_width / 5  + (config.screen_width / 3), 350, 0xffff00ff, 0xffffffff, march::WIDGET_CLICKABLE | march::WIDGET_HOVER, []() { return 2; }, 3)
    };
  }
};
