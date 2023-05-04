#include "screen.h"

namespace march {
  void Screen::store(const WidgetSet& set) {
    sets.push_back(set);
    ids.push_back(this->size);
    this->size++;
  }
  void Screen::switch_to(const size_t id) {
    this->active_set = id;
  }
}
