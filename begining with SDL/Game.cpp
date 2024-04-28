#include "Game.h"
#include "Defs.h"
#include "Graphics.h"
#include "Object.h"
#include "Map.h"
#include <SDL_ttf.h>

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

vector<pair<int, int>> Game::collision;

Object* Player = nullptr;



//Object* Rocket_x1 = nullptr;

int x = 0, y = 700;

void Game::init() {
    // Khoi tao game
    if (TTF_Init() == -1) {
            cout << "Khoi tao hien thi text that bat!\n";
        }
    else cout << "Khoi tao hien thi text thanh cong!\n";

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Khoi tao he thong thanh cong!\n";

        window = SDL_CreateWindow("Da", xPos, yPos, width, height, 0);
        if (window) {
            std::cout << "Khoi tao cua so thanh cong!\n";
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer) {
            std::cout << "Khoi tao renderer thanh cong!\n";
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        }


        isRunning = true;
    } else {
        isRunning = false;
        std::cout << "Khoi tao that bai!\n";
    }


    Player = new Object("Assets/Player.png", 0, 640 - 32, 0.5);
//    Rocket_x1 = new Object("Assets/Rocket_x.png", 0 - 64,600 , 1, collision);


}

void Game::handleEvent() {
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }

}

void Game::update() {
    Player->update();
//    collision.push_back(make_pair(Rocket_x1->destRect.x,Rocket_x1->destRect.y));
    check_collision();
//    collision.pop_back();

}

void Game::render() {
    SDL_RenderClear(renderer);

    // Render copy anh vao day
     Player->render();

//    if (Player->shot){
//            Rocket_x1->attack_x();
//    }
//    Player->write("Da");
//    Rocket_x1->write("Duy");
//    Vat3_1->write("Hung");

}
void Game::check_collision(){


   for(int i = 0; i < collision.size();i++){

        if ((Player->destRect.x + 32 >= collision[i].first + 5) && (Player->destRect.x + 32 <= collision[i].first + 32 - 5)
            && (Player->destRect.y > collision[i].second + 10) && (Player->destRect.y <= collision[i].second + 32 - 5))
        {
            cout << "yes1" << endl;
            Player->collide = true;
            break;
            return;
        }


        else if ((Player->destRect.x + 32 >= collision[i].first + 5) && (Player->destRect.x + 32 <= collision[i].first + 32 - 5)
            && (Player->destRect.y + 32 > collision[i].second + 10) && (Player->destRect.y + 32 <= collision[i].second + 32))
        {
            cout << "yes2" << endl;
            Player->collide = true;
            break;
            return;
        }

        else if ((Player->destRect.x >= collision[i].first + 5) && (Player->destRect.x <= collision[i].first + 32 - 5)
            && (Player->destRect.y > collision[i].second + 10) && (Player->destRect.y <= collision[i].second + 32 - 5))
        {
            cout << "yes3" << endl;
            Player->collide = true;
            break;
            return;
        }

        else if ((Player->destRect.x >= collision[i].first + 5) && (Player->destRect.x <= collision[i].first + 32 - 5)
            && (Player->destRect.y + 32 > collision[i].second + 10) && (Player->destRect.y + 32 <= collision[i].second + 32))
        {
            cout << "yes4" << endl;
            Player->collide = true;
            break;
            return;
        }

    }


}


void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    std::cout << "Xoa game thanh cong!\n";
}
