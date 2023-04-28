#pragma once

#include <vector>
#include <iostream>
#include <functional>
#include <thread>

#include <SDL.h>

enum WidgetFlags {
  WIDG_NA,
  WIDG_CLICKABLE,
};

struct Widget {
public:
  Widget(const uint16_t width, const uint16_t height, const uint16_t xpos, const uint16_t ypos, const uint32_t col, const WidgetFlags f) {
    rect.w = width;
    rect.h = height;
    rect.x = xpos;
    rect.y = ypos;
    colour = col;
    r = 0xff & (colour >> 24);
    g = 0xff & (colour >> 16);
    b = 0xff & (colour >> 8);
    a = 0xff & (colour);
    flags = f;
  }

  SDL_Rect rect;
  uint32_t colour;
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
  WidgetFlags flags;

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
  static constexpr uint16_t screen_width = 680;
  static constexpr uint16_t screen_height = 480;
  std::vector<Widget> widgets;
  SDL_Window* mWindow = nullptr;
  SDL_Renderer* mRenderer = nullptr;
  SDL_Surface* mScreenSurface = nullptr;
};

