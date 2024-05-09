#include "Game.h"
#include "Map.h"
#include "Menu.h"
#include "Object.h"
#include "AudioPlayer.h"
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



    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

    AudioPlayer* sech;


    sech->PlayMusic("music.mp3");
    while (GameCuaDa.running()) {
        if(Game::starst){
                MenuGame.Menu1_();
                Game::starst = false;
                Game::end_game = false;
                Object::Get_stars = true;
        }
        if(!Game::end_game){
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
        else{
            MenuGame.Menu2_();
            Game::score = 100;

        }
    }

    GameCuaDa.clean();
    return 0;
}
