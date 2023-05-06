#pragma once

#include <cstdint>
#include <functional>
#include <SDL.h>

#include "config.h"
namespace march {

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

  bool contains(const uint16_t x, const uint16_t y);
  void update(uint16_t new_w, uint16_t new_h, uint16_t old_w, uint16_t old_h);
  void setColNorm();
  void setColBright();
  void setCol(uint32_t col);

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
}
