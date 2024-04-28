#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Game.h"

class Graphics {
public:
    static SDL_Texture* loadTexture(const char* fileDir);
    static void Draw(SDL_Texture* texture, SDL_Rect destRect, const double angle);
};

#endif // GRAPHICS_H
