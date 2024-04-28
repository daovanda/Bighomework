#include "Game.h"
#include "Map.h"
Game GameCuaDa;
Map gameMap;
int main(int argc, char * argv[]) {
    const int FPS = 60;

    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    GameCuaDa.init();
    gameMap.loadMap();

    while (GameCuaDa.running()) {
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

    GameCuaDa.clean();
    return 0;
}
