#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Game {
public:
    void init();
    void handleEvent();
    void update();
    void render();
    void clean();
    void check_collision();
    bool running() {
        return isRunning;
    }
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static vector <pair<int, int>> collision;

private:
    bool isRunning = false;
    SDL_Window* window;
    int cnt = 0;
};

#endif // GAME_H
