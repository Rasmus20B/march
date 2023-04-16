#pragma once

#include <string>
#include <optional>
#include "trade.h"
namespace march {

  enum AreaType {
    AREA_TOWN,
    AREA_ROAD,
    AREA_SIZE
  };

  struct Area {
    std::string name;
    AreaType type;
    std::optional<Trader> trader;
  };

}
