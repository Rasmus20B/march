
#pragma once

#include <string_view>

#include "raylib.h"

struct WidgetText {
  std::string_view m_text;
  FontType m_font;
  uint16_t m_size;
  Color m_color;
};
