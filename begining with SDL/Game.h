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
    static bool starst;
    static bool end_game;
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static vector <pair<int, int>> collision;
    static double score;
    static int high_score;
private:
    bool isRunning = false;
    SDL_Window* window;

};

#endif // GAME_H
