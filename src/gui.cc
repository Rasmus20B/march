#include "gui.h"
#include "SDL_events.h"
#include "SDL_mouse.h"
#include "SDL_render.h"
#include "SDL_video.h"


constexpr bool Widget::contains(const uint16_t x, const uint16_t y) {
  return (x >= this->rect.x && x <= this->rect.x + this->rect.w
      && y >= this->rect.y && y <= this->rect.y + this->rect.h);
}

int Gui::init() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL init failed." << "\n";
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
  return 0;
}

uint8_t Gui::main_menu() {

  widgets.push_back(Widget(screen_width, screen_height, 0, 0, 0xFFC420ff, 0x181818ff, WIDGET_NA, nullptr, 1));
  widgets.push_back(Widget(280, 100, 50, 350 , 0x127f81ff, 0x181818ff, WIDGET_CLICKABLE | WIDGET_HOVER, []() {
        return 1;
        }, 2));
  widgets.push_back(Widget(280, 100, 350, 350 , 0xffff00ff, 0xffffffff, WIDGET_CLICKABLE | WIDGET_HOVER, [](){
        return 2;
        }, 3));

  SDL_RenderClear(mRenderer);
  for(auto w : widgets) {
    SDL_SetRenderDrawColor(mRenderer, w.r, w.g, w.b, w.a);
    SDL_RenderFillRect(mRenderer, &w.rect);
  }

  SDL_RenderPresent(mRenderer);


  int mouse_x, mouse_y;
  SDL_Event e;
  uint32_t choice = 0;
  while(!choice) {
    while(SDL_WaitEvent(&e)) {
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
              std::cout << "Invalid keypress: " << e.key.keysym.sym << "\n";
              break;
          }
          break;
        case SDL_MOUSEBUTTONDOWN:
          SDL_GetMouseState(&mouse_x, &mouse_y);
          for(auto w: widgets) {
            if(w.flags & WIDGET_CLICKABLE && w.contains(mouse_x, mouse_y)) {
              choice = w.call();
              goto end;
            }
          }
          break;
        case SDL_MOUSEMOTION:
          SDL_RenderClear(mRenderer);
          SDL_GetMouseState(&mouse_x, &mouse_y);
          std::cout << "NEW MOTION====================\n";
          for(auto &w : widgets) {
            bool h = (w.flags & WIDGET_HOVER);
            if(h && w.contains(mouse_x, mouse_y)) {
              if(!w.hover) {
                std::cout << "You are hovering over a button " << w.m_id << "\n";
                w.setColBright();
                update = true;
                w.hover = true;
              }
            } else if((h)) {
              if(w.hover) {
                std::cout << w.m_id << " Just a hover that isn't activated\n";
                std::cout << h << "\n";
                std::cout << std::hex << w.flags <<"\n";
                w.setColNorm();
                w.hover = false;
                update = true;
              }
            } else {
              std::cout << "not interacting with " << w.m_id << "\n";
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
        for(auto w : widgets) {
            std::cout << "setting " << w.m_id << " to colour : " << w.r << w.g << w.b <<  "\n";
            SDL_SetRenderDrawColor(mRenderer, w.r, w.g, w.b, w.a);
            SDL_RenderFillRect(mRenderer, &w.rect);
        }
        SDL_RenderPresent(mRenderer);
      }
    }
  }

end:
  widgets.clear();
  return choice; 
}

void Gui::main_loop() {

  uint8_t choice = main_menu();

  if(choice == 2) {
    return;
  }

  SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
  SDL_RenderClear(mRenderer);
  SDL_RenderPresent(mRenderer);


  SDL_Event e;
  bool quit = false;
  while (!quit){
      while (SDL_PollEvent(&e)){
        switch(e.type) {
          case SDL_QUIT:
            quit = true;
            break;
          case SDL_KEYDOWN:
            quit = true;
            break;
          case SDL_MOUSEBUTTONDOWN:
            for(auto &w: widgets) {
              int x, y;
              SDL_GetMouseState(&x, &y);
              if((x >= w.rect.x && x <= w.rect.w) && (y >= w.rect.y && y <= w.rect.h)) {
                std::cout << "You clicked the button\n";
              }
            }
            quit = true;
            break;
          }
      }
  }
}
