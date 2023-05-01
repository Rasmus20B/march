#pragma once

#include <numeric>

struct Config {
  uint16_t screen_width;
  uint16_t screen_height;
};

static Config config = { 640, 480 };
