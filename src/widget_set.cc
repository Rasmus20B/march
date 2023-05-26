#include "widget_set.h"
#include <raylib.h>

namespace march {
  WidgetReturn WidgetSet::handle_event() {
    bool update = false;
    uint32_t mousex = GetMouseX();
    uint32_t mousey = GetMouseY();
    WidgetReturn ret{WIDGET_RET_NA, 0};
    for(auto &w : widgets) {
      // Check for Hovers
      bool h = w.flags & WIDGET_HOVER;
      if(h && w.contains(mousex, mousey)) {
        if(!w.hover) {
         w.setColBright();
         w.hover = true;
        } 
      }else if((h)) {
        if(w.hover) {
          w.setColNorm();
          w.hover = false;
        }
      }
      // Check for mouse clicks
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
          w.contains(mousex, mousey) && w.flags & WIDGET_CLICKABLE) {
        auto c = w.call();
        ret.t = static_cast<WidgetReturnType>(static_cast<int>(ret.t) | static_cast<int>(c.t)); 
        ret.val = c.val;
      }
    }
    return ret;
  }

  void WidgetSet::store(const Widget& w) {
    widgets.push_back(w);
  }
  void WidgetSet::remove(const size_t id) {
    widgets.erase(widgets.begin() + id);
  }
}
