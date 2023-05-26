#include "gui.h"
// #include "sprite.h"
// #include "widget.h"
// #include <iterator>

namespace march {
  int Gui::init()  {
    InitWindow(config.screen_width, config.screen_height, "March Game");
    SetTargetFPS(60);
    this->screen.store(TitleMenu{});
    this->screen.store(MainHUD{});
    this->screen.store(TradeMenu{});
    this->screen.store(ScoutMenu{});
    this->screen.active_set = 0;
    return 0;
  }

  uint32_t handle_event() {
    return 0;
  }

  void Gui::main_loop() {
    while(!WindowShouldClose()) {
      std::cout << screen.active_set << "\n";
      auto r = screen.sets[screen.active_set].handle_event();
      BeginDrawing();
      ClearBackground(RAYWHITE);
      
      if(static_cast<int>(r.t) & static_cast<int>(WIDGET_RET_EXIT)) {
        return;
      }
      if(static_cast<int>(r.t) & static_cast<int>(WIDGET_RET_SWITCH_SCR)) {
        screen.switch_to(r.val);
      }

      for(auto &w : screen.sets[screen.active_set].widgets) {
        DrawRectangle(w.rect.x, w.rect.y, w.rect.width, w.rect.height, Color({w.r, w.g, w.b, w.a}));
        if(w.flags & WIDGET_TEXT) DrawText(w.text.m_text.data(), w.rect.x + (w.rect.width / 2), w.rect.y + (w.rect.height / 2), w.text.m_size, w.text.m_color);
      }
      DrawFPS((config.screen_width / 6) * 5, 20);
      EndDrawing();
    }
    CloseWindow();
  }
}
