#include "widget.h"

namespace march {

bool Widget::contains(const uint16_t x, const uint16_t y) {
return (x >= this->rect.x && x <= this->rect.x + this->rect.w
    && y >= this->rect.y && y <= this->rect.y + this->rect.h);
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
