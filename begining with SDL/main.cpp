#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <Windows.h>
#include "defs.h"
#include "Graphics.h"
#include<bits/stdc++.h>

using namespace std;



void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("xo.jpg");
    graphics.prepareScene(background);
    graphics.presentScene();

    int x, y;
    SDL_Event event;
    bool quit = false;
    while (! quit) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 quit = true;
                 break;
            case SDL_MOUSEBUTTONDOWN:
                 SDL_GetMouseState(&x, &y);
                 cerr << "Mouse-down at (" << x << ", " << y << ")\n";
                 break;
        }
        SDL_Delay(100);
    }

    graphics.quit();
    return 0;
}

