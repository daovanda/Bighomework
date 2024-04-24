// #pragma once
#ifndef Object_h
#define Object_h

#include "Game.h"
#include "Defs.h"
#include<bits/stdc++.h>
using namespace std;
class Object {
public:
    Object();

    Object(const char* fileDir, int x, int y, double scale, vector<pair<int,int>> &v);
    ~Object();
    vector <pair<int,int>> collision;
    void update();

    void render();
    void Check_ground();//fix here
    void roto();
    void attack(int x, int y);
    bool ontheground = true;
    void Gravity();

    SDL_Texture* objTexture;
    SDL_Rect destRect, src;


    bool isJumping = false;
    std::pair<int, int> velocity = {5, 4}; // toc to truc x va y
    int jumpStart = 0, jumpHeight = 90;
    int jumpLimit, jump = 0;
    int Ground_height = 600;

    double angle = 0;
    const double pi = M_PI;


};
#endif // Object_h
