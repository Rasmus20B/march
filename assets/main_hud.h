#pragma once

#include "../src/widget_set.h"
#include "../src/widget.h"

class MainHUD : public march::WidgetSet {
public:
  MainHUD() {
    widgets = {
      march::Widget(config.screen_width, config.screen_height, 0, 0, 0xffffffff, 0xffffffff, march::WIDGET_NA, nullptr, 0),
      march::Widget((config.screen_width / 3) * 2, config.screen_height / 3, 0, config.screen_height - config.screen_height / 3, 0xffff00ff, 0xffffffff, march::WIDGET_CLICKABLE, [](){
            std::cout << "You clicked the Yellow\n"; return 2;
            }, 1 ),
      march::Widget(config.screen_width / 3, config.screen_height - ((config.screen_height / 3) * 2), (config.screen_width / 3) * 2, config.screen_height - ((config.screen_height / 3) * 3), 0xff00ffff, 0xffffffff, march::WIDGET_CLICKABLE, []() {
            std::cout << "You clicked the Pink\n"; return 3;
            }, 2 ),
      march::Widget(((config.screen_width / 3) * 2), (config.screen_height / 3), ((config.screen_width / 3) * 2), config.screen_height - ((config.screen_height / 3) * 2), 0x00ffffff, 0xffffffff, march::WIDGET_CLICKABLE, []() {
            std::cout << "You clicked the Cyan\n"; return 4;
            }, 3),
      march::Widget(108, 160, 640 - 107, config.screen_height - 160, 0xff0000ff, 0xffffffff, march::WIDGET_CLICKABLE, []() {
            std::cout << "You Clicked the Red\n";
            std::cout << "Quitting Game!\n"; return 255;
            }, 4),
      march::Widget(108, 160, 640 - 214, config.screen_height - 160, 0x0000ffff, 0xffffffff, march::WIDGET_CLICKABLE, []() {
            std::cout << "You Clicked the Navy Blue\n"; return 5;
            }, 5)
    };
  }
};
