#include "widget_set.h"

namespace march {
  void WidgetSet::store(const Widget& w) {
    widgets.push_back(w);
  }
  void WidgetSet::remove(const size_t id) {
    widgets.erase(widgets.begin() + id);
  }
}
