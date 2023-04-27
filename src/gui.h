#pragma once

#include <vector>
#include <iostream>
#include <thread>

#include <SDL.h>

struct Widget {
  uint32_t colour;
  uint16_t id;
  SDL_Rect r;
};

class Gui {
 
public:
  Gui() = default;
  ~Gui() = default;
  Gui(const Gui&) = delete;

  int init();
  void main_loop();
  uint8_t main_menu();
  int exit();

private:
  static constexpr uint16_t screen_width = 1080;
  static constexpr uint16_t screen_height = 920;
  std::vector<Widget> widgets;
  SDL_Window* gWindow = NULL;
  SDL_Surface* gScreenSurface = NULL;
};

