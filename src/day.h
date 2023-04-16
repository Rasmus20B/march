#pragma once

#include "army.h"
#include "area.h"

namespace march {
struct day {
  Army& army; 
  Area& area;
  size_t day_num;
};
}
