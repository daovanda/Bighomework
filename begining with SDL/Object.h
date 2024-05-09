
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
    Object(const char* fileDir, int x, int y, int h, int w);

    ~Object();

    bool ontheground = true;
    static bool shot;
    bool isJumping = false;
    bool collide = false;
    static bool Get_stars;
    static bool You_win;
    void update();
    void render();
    void Check_ground();
    void attack_x();
    void Gravity();
    static void write(const char* s, int x, int y, int w, int h); //
    static vector <int> block;

    SDL_Texture* objTexture;
    SDL_Rect destRect;
    static SDL_Rect Rect;//

    std::pair<int, int> velocity = {5, 4};
    int jumpStart = 0, jumpHeight = 62;
    int Ground_height = 640;
    double angle = 0;
    const double pi = M_PI;

    static SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor);
    static TTF_Font* loadFont(const char* path, int size); //
    static SDL_Texture* text;//
    static TTF_Font* font;//

};
#endif // Object_h
