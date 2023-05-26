#include "widget.h"

#include <iostream>

namespace march {

[[gnu::const]]
bool Widget::contains(const uint16_t x, const uint16_t y) {
  return (x >= this->rect.x && x <= this->rect.x + this->rect.width
    && y >= this->rect.y && y <= this->rect.y + this->rect.height);
}

void Widget::update(uint16_t new_w, uint16_t new_h, uint16_t old_w, uint16_t old_h) {
  float w_sf = static_cast<float>(new_w) / static_cast<float>(old_w);
  float h_sf = static_cast<float>(new_h) / static_cast<float>(old_h);
  // this->rect.w = std::round(rect.w * w_sf);
  // this->rect.x = std::round(rect.x * w_sf);
  // this->rect.h = std::round(rect.h * h_sf);
  // this->rect.y = std::round(rect.y * h_sf);
}

void Widget::setCol(uint32_t col) {
  r = 0xff & (col >> 24);
  g = 0xff & (col >> 16);
  b = 0xff & (col >> 8);
  a = 0xff & (col);
}

void Widget::setColBright() {
  r = 0xff & (br_colour >> 24);
  g = 0xff & (br_colour >> 16);
  b = 0xff & (br_colour >> 8);
  a = 0xff & (br_colour);
}

void Widget::setColNorm() {
  r = 0xff & (norm_colour >> 24);
  g = 0xff & (norm_colour >> 16);
  b = 0xff & (norm_colour >> 8);
  a = 0xff & (norm_colour);
}
}
