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

#include "../assets/widget_sets.h"

namespace march {

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
  SDL_Window* mWindow = nullptr;
  SDL_Renderer* mRenderer = nullptr;
  SDL_Surface* mScreenSurface = nullptr;
};
}
