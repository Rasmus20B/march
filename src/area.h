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

  enum AreaNation {
    NATION_BABYLONIA,
    NATION_CARDUCHI,
    NATION_ARMENIA,
    NATION_TRAPEZUS,
    NATION_SIZE
  };

  constexpr std::array<std::string_view, NATION_SIZE> AreaNames = {
    "Babylonia",
    "Carduchi",
    "Armenia",
    "Trapezus"
  };

  struct Area {
    AreaNation nation;
    AreaType type;
    std::optional<Trader> trader;
  };

}
