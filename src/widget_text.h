
#include <SDL.h>
#include <SDL_ttf.h>
#include <string_view>

struct WidgetText {
  TTF_Font *m_font;
  std::string_view m_text;
  SDL_Color m_textcol;
};
