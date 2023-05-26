#pragma once

#include "../../src/widget_set.h"
#include "../../src/widget.h"

struct TitleMenu : public march::WidgetSet {
  TitleMenu() {
    widgets = {march::Widget(config.screen_width, config.screen_height, 0, 0,
                             0xFFC420ff, 0x181818ff, march::WIDGET_NA, nullptr,
                             0),
               march::Widget(config.screen_width, config.screen_height / 2, 0,
                             config.screen_height / 5, 0x000000ff, 0x000000ff,
                             march::WIDGET_TEXT, nullptr, "MARCH", FONT_DEFAULT, 50, 0xffffffff, 1),
               march::Widget(
                   config.screen_width / 3, config.screen_height / 5,
                   config.screen_width / 8, (config.screen_height / 3) * 2, 0x127f81ff, 0x181818ff,
                   march::WIDGET_CLICKABLE | march::WIDGET_HOVER | march::WIDGET_TEXT,
                   []() { return 1; }, "Start Game", FONT_DEFAULT, 20, 0x000000ff, 2),
               march::Widget(
                   config.screen_width / 3, config.screen_height / 5,
                   config.screen_width / 5 + (config.screen_width / 3), (config.screen_height / 3) * 2,
                   0xffff00ff, 0xffffffff,
                   march::WIDGET_CLICKABLE | march::WIDGET_HOVER | march::WIDGET_TEXT,
                   []() { return 2; }, "Quit", FONT_DEFAULT, 20,  0x000000ff, 3)};
  }
};
