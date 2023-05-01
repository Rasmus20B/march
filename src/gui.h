#pragma once

#include <vector>
#include <iostream>
#include <functional>
#include <thread>

#include <SDL.h>
#include <SDL_image.h>

#include "sprite.h"
#include "widget.h"
// #include "widget_set.h"
// #include "screen.h"

namespace march {
static constexpr uint16_t screen_width = 640;
static constexpr uint16_t screen_height = 480;

class Gui {
 
public:
  Gui() = default;
  ~Gui() = default;
  Gui(const Gui&) = delete;

  int init();
  void main_loop();
  uint8_t main_menu();
  int handle_event(SDL_Event const &e);
  void exit();
  void clear_screen();

private:
  std::vector<Widget> widgets;
  SDL_Window* mWindow = nullptr;
  SDL_Renderer* mRenderer = nullptr;
  SDL_Surface* mScreenSurface = nullptr;
};

struct MainGameScreen {
  MainGameScreen() = default;
  ~MainGameScreen() = default;

  std::vector<Widget> w = {
  Widget{screen_width, screen_height, 0, 0, 0xffffffff, 0xffffffff, WIDGET_NA, nullptr, 0},
  Widget{426, 200, 0, screen_height - 160, 0xffff00ff, 0xffffffff, WIDGET_CLICKABLE, [](){
        std::cout << "You clicked the Yellow\n"; return 0;
        }, 1 },
  Widget{214, 160, 426, screen_height - 320, 0xff00ffff, 0xffffffff, WIDGET_CLICKABLE, []() {
        std::cout << "You clicked the Pink\n"; return 0;
        }, 2 },
  Widget(214, 160, 426, screen_height - 480, 0x00ffffff, 0xffffffff, WIDGET_CLICKABLE, []() {
        std::cout << "You clicked the Cyan\n"; return 0;
        return 0;
        }, 3),
  Widget(108, 160, 640 - 107, screen_height - 160, 0xff0000ff, 0xffffffff, WIDGET_CLICKABLE, []() {
        std::cout << "You Clicked the Red\n";
        std::cout << "Quitting Game!\n"; return 1;
        }, 4),
  Widget(108, 160, 640 - 214, screen_height - 160, 0x0000ffff, 0xffffffff, WIDGET_CLICKABLE, []() {
        std::cout << "You Clicked the Navy Blue\n"; return 0;
        }, 5)
  };
};

struct MainMenu {
  MainMenu() = default;
  ~MainMenu() = default;
  std::array<Widget, 3> widgets {
    Widget{screen_width, screen_height, 0, 0, 0xFFC420ff, 0x181818ff, WIDGET_NA, nullptr, 0},
    Widget{280, 100, 40, 350, 0x127f81ff, 0x181818ff, WIDGET_CLICKABLE | WIDGET_HOVER, [](){ return 1; }, 1},
    Widget{280, 100, 40 + 280, 350, 0xffff00ff, 0xffffffff, WIDGET_CLICKABLE | WIDGET_HOVER, []() { return 2; }, 2}
  };
};
}
