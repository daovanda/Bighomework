#include "Game.h"

Game GameCuaDa;

int main(int argc, char * argv[]) {
    const int FPS = 60;

    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    GameCuaDa.init();

    while (GameCuaDa.running()) {
        frameStart = SDL_GetTicks();

        GameCuaDa.handleEvent();
        GameCuaDa.update();
        GameCuaDa.render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay)
            SDL_Delay(frameDelay - frameTime);
    }

    GameCuaDa.clean();
    return 0;
}
