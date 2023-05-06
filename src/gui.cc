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

int Gui::init() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL init failed.\n";
    return 1;
  } else {
    mWindow = SDL_CreateWindow( "March Game", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        config.screen_width, 
        config.screen_height, 
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

  /* Push Widget Sets to the Screen Container */
  this->screen.store(TitleMenu{});
  this->screen.store(MainHUD{});
  this->screen.store(TradeMenu{});
  this->screen.store(ScoutMenu{});

  return 0;
}

void Gui::exit() {
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  IMG_Quit();
  SDL_Quit();
}

void Gui::clear_screen() {
  SDL_RenderClear(mRenderer);
  SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 100);
  auto r = SDL_Rect{config.screen_width, config.screen_height, 0, 0};
  SDL_RenderDrawRect(mRenderer, &r);
  SDL_RenderPresent(mRenderer);
  SDL_UpdateWindowSurface(mWindow);
}

int Gui::handle_event(SDL_Event const &e) {
  switch(e.type) {
    case SDL_QUIT:
      return 255;
      break;
    case SDL_KEYDOWN:
      if(e.key.keysym.sym == 'q')
        return 255;
      break;
    case SDL_WINDOWEVENT:
      if(e.window.event == SDL_WINDOWEVENT_RESIZED) {
        SDL_SetWindowSize(mWindow, e.window.data1, e.window.data2);
        uint16_t old_w = config.screen_width;
        uint16_t old_h = config.screen_height;
        config.screen_width = e.window.data1;
        config.screen_height = e.window.data2;
        for(auto &s : screen.sets) {
          for(auto &w : s.widgets) {
            w.update(config.screen_width, config.screen_height, old_w, old_h);
          }
        }
        return 254;
      }
      break;
    case SDL_MOUSEMOTION:
      int mouse_x, mouse_y;
      SDL_GetMouseState(&mouse_x, &mouse_y);
      for(auto &w : screen.sets[screen.active_set].widgets) {
        bool h = w.flags & WIDGET_HOVER;
        if(h && w.contains(mouse_x, mouse_y)) {
          if(!w.hover) {
            w.setColBright();
            w.hover = true;
          }
        } else if((h)) {
          if(w.hover) {
            w.setColNorm();
            w.hover = false;
          }
        }
      }
      return 254;
      break;
    case SDL_MOUSEBUTTONDOWN:
      for(auto &w: screen.sets[screen.active_set].widgets) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(w.flags & WIDGET_CLICKABLE && w.contains(x, y)) {
          return(w.call());
        }
      }
      break;
    default:
      break;
  }
  return 0;
}
void Gui::main_loop() {
  SDL_Surface *image = IMG_Load("../assets/spriteSheet1.bmp");
  if(!image) std::cerr << "Unable to load image\n";
  SDL_Texture *texture = SDL_CreateTextureFromSurface(mRenderer, image);

  SDL_Event e;
  bool quit = false;
  bool update = true;
  bool w_update = false;

  while (!quit){
    int ticks = SDL_GetTicks();
    // int sprite_n = (ticks / 100) % 4;
    // SDL_Rect srcrect = { sprite_n * 32, 0, 32, 64 };
    // SDL_Rect dstrect = { 32, 0, 32, 64 };
    while (SDL_PollEvent(&e)){
      switch(handle_event(std::move(e))) {
        case 1:
          screen.switch_to(1);
          update = true;
          break;
        case 2:
          break;
        case 3:
          if(screen.active_set == 1) screen.switch_to(2);
          else screen.switch_to(1);
          update = true;
          break;
        case 4:
          if(screen.active_set == 1) screen.switch_to(3);
          else screen.switch_to(1);
          update = true;
          break;
        case 254:
          update = true;
          break;
        case 255:
          quit = 1;
        default:
          break;
      }
    }
    SDL_RenderClear(mRenderer);
    if(update) {
      for(auto &w : screen.sets[screen.active_set].widgets) {
        SDL_SetRenderDrawColor(mRenderer, w.r, w.g, w.b, w.a);
        SDL_RenderFillRect(mRenderer, &w.rect);
      }
      SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
      SDL_RenderPresent(mRenderer);
    }
    update = false;
    // if(screen.active_set == 1) {
    //   SDL_RenderCopy(mRenderer, texture, &srcrect, &dstrect);
    // }
  }
  Gui::exit();
}
}
