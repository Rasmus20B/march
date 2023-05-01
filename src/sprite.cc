#include "sprite.h"
#include "SDL_image.h"
#include "SDL_surface.h"

namespace march {
Spritesheet::Spritesheet(const char *path, int rows, int columns) {
  mSpritesheetImage = SDL_LoadBMP(path);
  mClip.w = mSpritesheetImage->w / columns;
  mClip.h = mSpritesheetImage->h / rows;
}

Spritesheet::~Spritesheet() {
  SDL_FreeSurface(mSpritesheetImage);
}

void Spritesheet::selectSprite(int x, int y) {
  mClip.x = x * mClip.w;
  mClip.y = y * mClip.h;
}

void Spritesheet::draw(SDL_Surface *surface, SDL_Rect *pos) {
  SDL_BlitSurface(mSpritesheetImage, &mClip, surface, pos);
}
}
