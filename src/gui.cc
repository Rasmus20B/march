#include "gui.h"
#include "SDL_events.h"
#include "SDL_mouse.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_timer.h"
#include "SDL_video.h"
#include "sprite.h"
#include <iterator>


namespace march {

constexpr bool Widget::contains(const uint16_t x, const uint16_t y) {
return (x >= this->rect.x && x <= this->rect.x + this->rect.w
    && y >= this->rect.y && y <= this->rect.y + this->rect.h);
}

int Gui::init() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL init failed.\n";
    return 1;
  } else {
    mWindow = SDL_CreateWindow( "March Game", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        screen_width, 
        screen_height, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if( mWindow == nullptr )
    {
      std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
      return 1;
    }
    else
    {
      mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
      if (!mRenderer) {
        std::cerr << "Error initializing _renderer: " << SDL_GetError() << "\n";
      } 
    }
  }

  if(!IMG_Init(IMG_INIT_PNG)) {
    std::cerr << "SDL IMG init failed.\n";
    return 1;
  }
  return 0;
}

void Gui::exit() {
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  IMG_Quit();
  SDL_Quit();
}

uint8_t Gui::main_menu() {

  MainMenu menu;

  SDL_RenderClear(mRenderer);
  for(auto w : menu.widgets) {
    SDL_SetRenderDrawColor(mRenderer, w.r, w.g, w.b, w.a);
    SDL_RenderFillRect(mRenderer, &w.rect);
  }
  SDL_RenderPresent(mRenderer);

  int mouse_x, mouse_y;
  SDL_Event e;
  uint32_t choice = 0;
  while(!choice) {
    while(SDL_WaitEvent(&e)) {
      std::cout << "Found Event " << e.type << "\n";
      bool update = false;
      switch(e.type) {
        case SDL_KEYDOWN:
          switch(e.key.keysym.sym) {
            case SDLK_1:
              choice = 1;
              goto end;
            case SDLK_q:
              choice = 2;
              goto end;
            default:
              break;
          }
          break;
        case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&mouse_x, &mouse_y);
          for(auto w: menu.widgets) {
            if(w.flags & WIDGET_CLICKABLE && w.contains(mouse_x, mouse_y)) {
              choice = w.call();
              goto end;
            }
          }
          break;
        case SDL_MOUSEMOTION:
          SDL_GetMouseState(&mouse_x, &mouse_y);
          for(auto &w : menu.widgets) {
            bool h = w.flags & WIDGET_HOVER;
            if(h && w.contains(mouse_x, mouse_y)) {
              if(!w.hover) {
                w.setColBright();
                update = true;
                w.hover = true;
              }
            } else if((h)) {
              if(w.hover) {
                w.setColNorm();
                w.hover = false;
                update = true;
              }
            }
          }
          break;
        case SDL_QUIT:
          choice = 2;
          break;
        default:
          continue;
      }
      // Redraw
      if(update) {
        SDL_RenderClear(mRenderer);
        for(auto w : menu.widgets) {
            SDL_SetRenderDrawColor(mRenderer, w.r, w.g, w.b, w.a);
            SDL_RenderFillRect(mRenderer, &w.rect);
        }
        SDL_RenderPresent(mRenderer);
      }
    }
  }

end:
  return choice; 
}

void Gui::clear_screen() {
  SDL_RenderClear(mRenderer);
  SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 100);
  auto r = SDL_Rect{screen_width, screen_height, 0, 0};
  SDL_RenderDrawRect(mRenderer, &r);
  SDL_RenderPresent(mRenderer);
  SDL_UpdateWindowSurface(mWindow);
}

int Gui::handle_event(SDL_Event const &e) {
  switch(e.type) {
    case SDL_QUIT:
      return 1;
      break;
    case SDL_KEYDOWN:
      return 1;
      break;
    case SDL_MOUSEBUTTONDOWN:
      for(auto &w: widgets) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(w.flags & WIDGET_CLICKABLE && (w.contains(x, y))) {
          switch(w.call()) {
            case 1:
              return 1;
              break;
            default:
              break;
          }
        }
      }
      break;
    case SDL_MOUSEMOTION:
      break;
    default:
      break;
  }
  return 0;
}
void Gui::main_loop() {

  uint8_t choice = Gui::main_menu();

  if(choice == 2) {
    return;
  }

  clear_screen();

  SDL_Surface *image = IMG_Load("../assets/spriteSheet1.bmp");
  if(!image) std::cerr << "Unable to load image\n";
  SDL_Texture *texture = SDL_CreateTextureFromSurface(mRenderer, image);

  SDL_Event e;
  bool quit = false;
  MainGameScreen scr;
  widgets.insert(widgets.begin(), scr.w.begin(), scr.w.end());

  std::cout << "Widgets Allocated: " << widgets.size() << "\n";
  while (!quit){
    int ticks = SDL_GetTicks();
    int sprite_n = (ticks / 100) % 4;
    SDL_Rect srcrect = { sprite_n * 32, 0, 32, 64 };
    SDL_Rect dstrect = { 32, 0, 32, 64 };
    while (SDL_PollEvent(&e)){
      if(handle_event(std::move(e)) == 1) {
        return;
      }
    }
    SDL_RenderClear(mRenderer);
    for(auto &w : widgets) {
        SDL_SetRenderDrawColor(mRenderer, w.r, w.g, w.b, w.a);
        SDL_RenderFillRect(mRenderer, &w.rect);
    }
    SDL_RenderCopy(mRenderer, texture, &srcrect, &dstrect);
    SDL_RenderPresent(mRenderer);
  }
  Gui::exit();
}
}
