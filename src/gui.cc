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
    return 0;
  }

  uint32_t handle_event() {

  }

  void Gui::main_loop() {
    screen.switch_to(0);
    while(!WindowShouldClose()) {
    bool update = true;
      for(auto &w : CUR_SCREEN.widgets) {
        bool h = w.flags & WIDGET_HOVER;
        if(h && w.contains(GetMouseX(), GetMouseY())) {
          if(!w.hover) {
           w.setColBright();
           w.hover = true;
          } else if((h)) {
            if(w.hover) {
             w.setColNorm();
             w.hover = false;
            }
          }
        }
      }
      BeginDrawing();
      if(update) {
        ClearBackground(RAYWHITE);
        DrawText("March", 20, 20, 40, BLACK);
        for(auto &w : screen.sets[screen.active_set].widgets) {
          DrawRectangle(w.rect.x, w.rect.y, w.rect.width, w.rect.height, Color({w.r, w.g, w.b, w.a}));
          DrawText(w.text.m_text.data(), w.rect.x + (w.rect.width / 2), w.rect.y + (w.rect.height / 2), w.text.m_size, w.text.m_color);
        }
      }
      DrawFPS((config.screen_width / 6) * 5, 20);
      EndDrawing();
      update = false;
    }
    CloseWindow();
  }



}
// int Gui::init() {
//
//   // if(SDL_Init(SDL_INIT_VIDEO) < 0) {
//   //   std::cerr << "SDL init failed.\n";
//   //   return 1;
//   // } else {
//   //   mWindow = SDL_CreateWindow( "March Game", 
//   //       SDL_WINDOWPOS_CENTERED, 
//   //       SDL_WINDOWPOS_CENTERED, 
//   //       config.screen_width, 
//   //       config.screen_height, 
//   //       SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
//   //   if( mWindow == nullptr )
//   //   {
//   //     std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
//   //     return 1;
//   //   }
//   //   else
//   //   {
//   //     mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
//   //     if (!mRenderer) {
//   //       std::cerr << "Error initializing _renderer: " << SDL_GetError() << "\n";
//   //     } 
//   //   }
//   // }
//   //
//   // if(!IMG_Init(IMG_INIT_PNG)) {
//   //   std::cerr << "SDL IMG init failed.\n";
//   //   return 1;
//   // }
//   //
//   // if ( TTF_Init() < 0 ) {
//   //   std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << "\n";
//   // }
//   //
//   // /* Push Widget Sets to the Screen Container */
   //
//   // return 0;
// }
//
// void Gui::exit() {
// }
//
// void Gui::clear_screen() {
// }
//
// int Gui::handle_event(SDL_Event const &e) {
//   switch(e.type) {
//     case SDL_QUIT:
//       return 255;
//       break;
//     case SDL_KEYDOWN:
//       if(e.key.keysym.sym == 'q')
//         return 255;
//       break;
//     case SDL_WINDOWEVENT:
//       if(e.window.event == SDL_WINDOWEVENT_RESIZED) {
//         SDL_SetWindowSize(mWindow, e.window.data1, e.window.data2);
//         uint16_t old_w = config.screen_width;
//         uint16_t old_h = config.screen_height;
//         config.screen_width = e.window.data1;
//         config.screen_height = e.window.data2;
//         for(auto &s : screen.sets) {
//           for(auto &w : s.widgets) {
//             w.update(config.screen_width, config.screen_height, old_w, old_h);
//           }
//         }
//         return 254;
//       }
//       break;
//     case SDL_MOUSEMOTION:
//       int mouse_x, mouse_y;
//       SDL_GetMouseState(&mouse_x, &mouse_y);
//       for(auto &w : screen.sets[screen.active_set].widgets) {
//         bool h = w.flags & WIDGET_HOVER;
//         if(h && w.contains(mouse_x, mouse_y)) {
//           if(!w.hover) {
//             w.setColBright();
//             w.hover = true;
//           }
//         } else if((h)) {
//           if(w.hover) {
//             w.setColNorm();
//             w.hover = false;
//           }
//         }
//       }
//       return 254;
//       break;
//     case SDL_MOUSEBUTTONDOWN:
//       for(auto &w: screen.sets[screen.active_set].widgets) {
//         int x, y;
//         SDL_GetMouseState(&x, &y);
//         if(w.flags & WIDGET_CLICKABLE && w.contains(x, y)) {
//           return(w.call());
//         }
//       }
//       break;
//     default:
//       break;
//   }
//   return 0;
// }
// void Gui::main_loop() {
//   // SDL_Surface *image = IMG_Load("../assets/sprite_sheets/spriteSheet1.bmp");
//   // if(!image) std::cerr << "Unable to load image\n";
//   // SDL_Texture *texture = SDL_CreateTextureFromSurface(mRenderer, image);
//
//   // SDL_Event e;
//   bool quit = false;
//   bool update = true;
//   bool w_update = false;
//
//   while (!quit){
//     // int ticks = SDL_GetTicks();
//     // int sprite_n = (ticks / 100) % 4;
//     // SDL_Rect srcrect = { sprite_n * 32, 0, 32, 64 };
//     // SDL_Rect dstrect = { 32, 0, 32, 64 };
//     // while (SDL_PollEvent(&e)){
//     //   switch(handle_event(std::move(e))) {
//         // case 1:
//         //   screen.switch_to(1);
//         //   update = true;
//         //   break;
//         // case 2:
//         //   break;
//         // case 3:
//         //   if(screen.active_set == 1) screen.switch_to(2);
//         //   else screen.switch_to(1);
//         //   update = true;
//         //   break;
//         // case 4:
//         //   if(screen.active_set == 1) screen.switch_to(3);
//         //   else screen.switch_to(1);
//         //   update = true;
//         //   break;
//         // case 254:
//         //   update = true;
//         //   break;
//         // case 255:
//         //   quit = 1;
//         // default:
//         //   break;
//       }
//     }
//     // SDL_RenderClear(mRenderer);
//     // if(update) {
//     //   for(auto &w : screen.sets[screen.active_set].widgets) {
//     //     SDL_SetRenderDrawColor(mRenderer, w.r, w.g, w.b, w.a);
//     //     SDL_RenderFillRect(mRenderer, &w.rect);
//     //     if(w.flags & march::WIDGET_TEXT) {
//     //       SDL_Texture* text_texture;
//     //       SDL_Surface* text = TTF_RenderText_Solid( w.text.m_font, w.text.m_text.data(), w.text.m_textcol );
//     //       text_texture = SDL_CreateTextureFromSurface( mRenderer, text );
//     //       SDL_Rect dest = { w.rect.x, w.rect.y, text->w , text->h  };
//     //       SDL_RenderCopy( mRenderer, text_texture, &dest, nullptr );
//     //     }
//     //   }
//     //   SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
//     //   SDL_RenderPresent(mRenderer);
//     // }
//     // update = false;
//     // if(screen.active_set == 1) {
//     //   SDL_RenderCopy(mRenderer, texture, &srcrect, &dstrect);
//     // }
//   }
//   // Gui::exit();
// // }
// // }
