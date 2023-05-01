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
#include "screen.h"

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
  Screen screen;
  std::vector<Widget> widgets;
  SDL_Window* mWindow = nullptr;
  SDL_Renderer* mRenderer = nullptr;
  SDL_Surface* mScreenSurface = nullptr;
};
}
