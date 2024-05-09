#include "Game.h"
#include "Defs.h"
#include "Graphics.h"
#include "Object.h"
#include "Map.h"
#include <SDL_ttf.h>
#include <bits/stdc++.h>
using namespace std;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

vector<pair<int, int>> Game::collision;
bool Game::starst = true;
bool Game::end_game = false;
int Game::score = 100;

Object* Player = nullptr;
Object* Rocket_x1 = nullptr;
Object* Stars = nullptr;
Object* Door = nullptr;
Object* Stars_nomal = nullptr;
Object* Stars_gold_1 = nullptr;
Object* Stars_gold_2 = nullptr;
Object* Stars_gold_3 = nullptr;


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
    Rocket_x1 = new Object("Assets/Rocket_x.png", 0 - 32*2,600 , 0.5);
    Stars = new Object("Assets/Stars.png", 960 - 32*2, 640 - 8*32 - 16, 0.75);
    Door = new Object("Assets/Door.png", 960 - 64, 0, 1);
    Stars_gold_1 = new Object("Assets/Stars_gold.png", 480 - 32, 0, 0.5);
    Stars_gold_2 = new Object("Assets/Stars_gold.png", 480 - 32 - 32, 0, 0.5);
    Stars_gold_3 = new Object("Assets/Stars_gold.png", 480, 0, 0.5);
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
    collision.push_back(make_pair(Rocket_x1->destRect.x,Rocket_x1->destRect.y));
    check_collision();
    collision.pop_back();

}

void Game::render() {
    SDL_RenderClear(renderer);

    // Render copy anh vao day
    Player->render();
    Door->render();
    if(Player->Get_stars){
        Stars->render();

    }
    if(Object::shot){
        Rocket_x1->attack_x();
    }

    if(!Player->Get_stars){
        Stars_gold_1->render();
        Stars_gold_2->render();
        Stars_gold_3->render();
    }
    if(!Player->You_win){
        string s1 = "Your Score :";
        string s2 = to_string(score);
        Object::write( s1.c_str(), 0, -5, 50, 100);
        Object::write( s2.c_str(), 100, -5, 50, 50);
    }
}
void Game::check_collision(){


   for(int i = 0; i < collision.size();i++){

        if ((Player->destRect.x + 32 >= collision[i].first + 5) && (Player->destRect.x + 32 <= collision[i].first + 32 - 5)
            && (Player->destRect.y > collision[i].second + 10) && (Player->destRect.y <= collision[i].second + 32 - 5))
        {
            cout << "yes1" << endl;
            Player->collide = true;
            Game::score--;
            break;
            return;
        }


        else if ((Player->destRect.x + 32 >= collision[i].first + 5) && (Player->destRect.x + 32 <= collision[i].first + 32 - 5)
            && (Player->destRect.y + 32 > collision[i].second + 10) && (Player->destRect.y + 32 <= collision[i].second + 32))
        {
            cout << "yes2" << endl;
            Player->collide = true;
            Game::score--;
            break;
            return;
        }

        else if ((Player->destRect.x >= collision[i].first + 5) && (Player->destRect.x <= collision[i].first + 32 - 5)
            && (Player->destRect.y > collision[i].second + 10) && (Player->destRect.y <= collision[i].second + 32 - 5))
        {
            cout << "yes3" << endl;
            Player->collide = true;
            Game::score--;
            break;
            return;
        }

        else if ((Player->destRect.x >= collision[i].first + 5) && (Player->destRect.x <= collision[i].first + 32 - 5)
            && (Player->destRect.y + 32 > collision[i].second + 10) && (Player->destRect.y + 32 <= collision[i].second + 32))
        {
            cout << "yes4" << endl;
            Player->collide = true;
            Game::score--;
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
