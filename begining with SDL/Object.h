#pragma once
#include "Game.h"

class Object {
public:
    Object();
    Object(const char* fileDir, int x, int y);
    ~Object();

    void update();

    void render();

    bool isGrounded();

    SDL_Texture* objTexture;
    SDL_Rect destRect, src;
    bool isJumping = false;
    std::pair<int, int> velocity = {10, 0};
    int jumpStart = 0, jumpHeight = 100;
    int jumpLimit, jump = 0;
    double angle = 0;
    const double pi = 3.14156;
};
