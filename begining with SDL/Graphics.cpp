#include "Graphics.h"

SDL_Texture* Graphics::loadTexture(const char* fileDir) {
    SDL_Surface* temp = IMG_Load(fileDir);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, temp);
    SDL_FreeSurface(temp);
    return texture;
}

void Graphics::Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect, const double angle) {
//    SDL_RenderCopy(Game::renderer, texture, NULL, &destRect);
    SDL_RenderCopyEx(Game::renderer, texture, NULL, &destRect, angle, NULL, SDL_FLIP_NONE);
}
