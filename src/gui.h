#pragma once

#include <vector>
#include <iostream>
#include <functional>
#include <thread>

#include <SDL.h>
#include <SDL_image.h>

#include "sprite.h"

namespace march {
static constexpr uint16_t screen_width = 640;
static constexpr uint16_t screen_height = 480;
enum WidgetFlags {
  WIDGET_NA = 1,
  WIDGET_CLICKABLE = 2,
  WIDGET_HOVER = 4,
};

struct Widget {
public:
  Widget(const uint16_t width, const uint16_t height, const uint16_t xpos, const uint16_t ypos, const uint32_t col, const uint32_t br_col, uint8_t f, std::function<uint32_t()> fun, size_t id) {
    rect.w = width;
    rect.h = height;
    rect.x = xpos;
    rect.y = ypos;
    norm_colour = col;
    br_colour = br_col;
    r = 0xff & (norm_colour >> 24);
    g = 0xff & (norm_colour >> 16);
    b = 0xff & (norm_colour >> 8);
    a = 0xff & (norm_colour);
    flags = f;
    call = fun;
    m_id = id;
  }

  ~Widget() = default;

  constexpr bool contains( uint16_t x,  uint16_t y);

  void setCol(uint32_t col) {
    r = 0xff & (col >> 24);
    g = 0xff & (col >> 16);
    b = 0xff & (col >> 8);
    a = 0xff & (col);
  }

  void setColBright() {
    r = 0xff & (br_colour >> 24);
    g = 0xff & (br_colour >> 16);
    b = 0xff & (br_colour >> 8);
    a = 0xff & (br_colour);
  }
  
  void setColNorm() {
    r = 0xff & (norm_colour >> 24);
    g = 0xff & (norm_colour >> 16);
    b = 0xff & (norm_colour >> 8);
    a = 0xff & (norm_colour);
  }

  SDL_Rect rect;
  std::function<uint32_t()> call;
  size_t m_id;
  uint32_t flags;
  uint32_t norm_colour;
  uint32_t br_colour;
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
  bool hover = false;
};

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
