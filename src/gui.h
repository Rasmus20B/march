#pragma once

#include <vector>
#include <iostream>
#include <functional>
#include <thread>

#include <SDL.h>

enum WidgetFlags {
  WIDGET_NA = 1,
  WIDGET_CLICKABLE = 2,
  WIDGET_HOVER = 4,
};

struct Widget {
public:
  Widget(const uint16_t width, const uint16_t height, const uint16_t xpos, const uint16_t ypos, const uint32_t col, const uint32_t br_col, uint8_t f, std::function<uint32_t()> fun, int id) {
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

  constexpr bool contains(const uint16_t x, const uint16_t y);

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
  uint32_t flags;
  uint32_t norm_colour;
  uint32_t br_colour;
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
  bool hover = false;
  int m_id;
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

