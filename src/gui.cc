#include "gui.h"
#include "SDL_events.h"
#include "SDL_mouse.h"
#include "SDL_render.h"
#include "SDL_video.h"

int Gui::init() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL init failed." << std::endl;
    return 1;
  } else {
    mWindow = SDL_CreateWindow( "March Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if( mWindow == nullptr )
    {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
      return 1;
    }
    else
    {
      mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
      if (mRenderer == nullptr) {
        std::cout << "Error initializing _renderer: " << SDL_GetError() << std::endl;
      } 
    }
  }
  return 0;
}

uint8_t Gui::main_menu() {

  widgets.push_back(Widget(screen_width, screen_height, 0, 0, 0xFFC420ff, WIDG_NA));
  widgets.push_back(Widget(100, 200, 100, 60, 0x127f81ff, WIDG_CLICKABLE));
  widgets.push_back(Widget(50, 25, 200, 300, 0xffffffff, WIDG_CLICKABLE));

  SDL_RenderClear(mRenderer);
  SDL_Rect background { screen_width, screen_height, 0, 0 };
  SDL_SetRenderDrawColor(mRenderer, 100, 100, 100, 255);
  SDL_RenderFillRect(mRenderer, &background);
  for(auto w : widgets) {
    SDL_SetRenderDrawColor(mRenderer, w.r, w.g, w.b, w.a);
    SDL_RenderFillRect(mRenderer, &w.rect);
  }

  SDL_RenderPresent(mRenderer);

  SDL_Event e;
  uint32_t choice = 0;
  while(!choice) {
    while(SDL_WaitEvent(&e))
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
          int x, y;
          SDL_GetMouseState(&x, &y);
          for(auto w: widgets) {
            if(w.flags & WIDG_CLICKABLE 
                && (x >= w.rect.x && x <= w.rect.x + w.rect.w) 
                && (y >= w.rect.y && y <= w.rect.y + w.rect.h)) {
              std::cout << "You clicked the button\n";
              break;
            }
          }
          break;
        case SDL_QUIT:
          choice = 2;
          break;
        default:
          continue;
      }
  }

end:
  return choice; 
}

void Gui::main_loop() {

  uint8_t choice = main_menu();

  if(choice == 2) {
    return;
  }

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
