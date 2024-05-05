#include "Game.h"
#include "Map.h"
#include "Menu.h"
#include<bits/stdc++.h>
using namespace std;
Game GameCuaDa;
Map gameMap;
Menu MenuGame;
int main(int argc, char * argv[]) {
    const int FPS = 60;

    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    GameCuaDa.init();
    gameMap.loadMap();
    MenuGame.Menu1_();
    while (GameCuaDa.running()) {


        if(MenuGame.Menu1){
            frameStart = SDL_GetTicks();

            GameCuaDa.handleEvent();
            GameCuaDa.update();
            GameCuaDa.render();
            gameMap.renderMap();
            frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < frameDelay)
                SDL_Delay(frameDelay - frameTime);
                SDL_RenderPresent(Game::renderer);

            }
    }

    GameCuaDa.clean();
    return 0;
}
