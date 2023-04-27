#include "gui.h"
#include "SDL_events.h"

int Gui::init() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL init failed." << std::endl;
    return 1;
  } else {
    gWindow = SDL_CreateWindow( "March Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
      return 1;
    }
    else
    {
      //Get window surface
      gScreenSurface = SDL_GetWindowSurface( gWindow );
    }
  }
  return 0;
}

uint8_t Gui::main_menu() {
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

  SDL_Event e;
  bool quit = false;
  while (!quit){
      while (SDL_PollEvent(&e)){
          if (e.type == SDL_QUIT){
              quit = true;
          }
          if (e.type == SDL_KEYDOWN){
              quit = true;
          }
          if (e.type == SDL_MOUSEBUTTONDOWN){
              quit = true;
          }
      }
  }
}
