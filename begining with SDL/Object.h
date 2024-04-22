#pragma once
#include "Game.h"
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

    bool isGrounded();
    SDL_Texture* objTexture;
    SDL_Rect destRect, src;


    bool isJumping = false;
    std::pair<int, int> velocity = {5, 0}; // toc to truc x va y
    int jumpStart = 0, jumpHeight = 100;
    int jumpLimit, jump = 0;
    int do_cao_mat_dat = 0;

    double angle = 0;
    const double pi = M_PI;


};
