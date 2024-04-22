#include "Game.h"
#include "Defs.h"
#include "Graphics.h"
#include "Object.h"
#include "Map.h"


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
vector <pair<int,int>> Game::collision;
Object* Player = nullptr;


Object* Vat1 = nullptr;
Object* Vat2_1 = nullptr;
Object* Vat2_2 = nullptr;
Object* Vat3 = nullptr;
Object* Vat3_1= nullptr;
Object* Vat3_2= nullptr;
Object* Vat3_3= nullptr;
Object* Vat3_4= nullptr;
Object* Vat3_5= nullptr;
Object* Vat3_6= nullptr;


int x = 0, y = 700;

void Game::init() {
    // Khoi tao game
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Khoi tao he thong thanh cong!\n";

        window = SDL_CreateWindow(title, xPos, yPos, width, height, 0);
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


    Vat1 = new Object("Assets/Vat1.png", 250, 600 - 64, 1,collision);
    collision.push_back(make_pair(250,600 - 64));
    Vat2_1 = new Object("Assets/Vat2.png", 250 - 32, 600 - 64*0.5, 0.5,collision);
    collision.push_back(make_pair(250 - 32,600 - 32));
    Vat2_2 = new Object("Assets/Vat2.png", 800 - 64, 600 - 64, 1, collision);
    collision.push_back(make_pair(800 - 64, 600 - 64));
    Vat3_1 = new Object("Assets/Vat3.png",800 - 64*2, 600 - 64, 1, collision);
    collision.push_back(make_pair(800 - 64*2, 600 - 64));
    Vat3_2 = new Object("Assets/Vat3.png",800 - 64*3, 600 - 64, 1, collision);
    collision.push_back(make_pair(800 - 64*3, 600 - 64));
    Vat3_3 = new Object("Assets/Vat3.png",800 - 64*4, 600 - 64, 1, collision);
    collision.push_back(make_pair(800 - 64*4, 600 - 64));
    Vat3_4 = new Object("Assets/Vat3.png",800 - 64*6, 500 - 64, 1, collision);
    collision.push_back(make_pair(800 - 64*6, 500 - 64));
    Vat3_5 = new Object("Assets/Vat3.png",800 - 64*8, 450 - 64, 1, collision);
    collision.push_back(make_pair(800 - 64*8, 450 - 64));
    collision.push_back(make_pair(800 - 64*10, 400 - 64));
    Vat3_6 = new Object("Assets/Vat3.png",800 - 64*10, 400 - 64, 1, collision);
    Player = new Object("Assets/Player.png", 0, 600 - 32, 0.5, collision);



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
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Render copy anh vao day
    Player->render();
    Vat1->render();
    Vat2_1->render();
    Vat2_2->render();
    Vat3_1->render();
    Vat3_2->render();
    Vat3_3->render();
    Vat3_4->render();
    Vat3_5->render();
    Vat3_6->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Xoa game thanh cong!\n";
}
