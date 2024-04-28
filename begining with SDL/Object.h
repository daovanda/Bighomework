// #pragma once
#ifndef Object_h
#define Object_h

#include "Game.h"
#include "Defs.h"
#include<bits/stdc++.h>
#include <SDL_ttf.h>
using namespace std;
class Object {
public:
    Object();

    Object(const char* fileDir, int x, int y, double scale);
    ~Object();
    void update();
    void render();
    void Check_ground();//fix here
    void roto();
    void attack_x();
    bool ontheground = true;
    void Gravity();
    void write(const char* s);
    static vector <int> block;

    SDL_Texture* objTexture;
    SDL_Rect destRect;

    bool shot = false;
    bool isJumping = false;
    std::pair<int, int> velocity = {5, 4};
    int jumpStart = 0, jumpHeight = 60;
    int jumpLimit, jump = 0;
    int Ground_height = 640;
    bool collide=false;
    double angle = 0;
    const double pi = M_PI;
    SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor);
    TTF_Font* loadFont(const char* path, int size);

    SDL_Texture* text;
    TTF_Font* font;

};
#endif // Object_h
