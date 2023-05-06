#include "screen.h"

namespace march {
  void Screen::store(const WidgetSet& set) {
    sets.push_back(set);
    ids.push_back(this->size);
    this->size++;
  }
  void Screen::switch_to(const size_t id) {
    /* Reset the attributes of a given 'widgetSet' so 
     * that it's fresh when we access it again. */
    for(auto &w : this->sets[this->active_set].widgets) {
      w.hover = false;
      w.setColNorm();
    }
    this->active_set = id;
  }
}
