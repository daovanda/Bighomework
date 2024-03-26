#include "Game.h"
#include "Defs.h"
#include "Graphics.h"
#include "Object.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Object* Player = nullptr;

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

    Player = new Object("Assets/Player.png", 0, 600 - 64);
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

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Xoa game thanh cong!\n";
}
