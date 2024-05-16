#ifndef Menu_h
#define Menu_h
#include "Game.h"
#include "Graphics.h"
#include "Object.h"
#include<bits/stdc++.h>
using namespace std;
class Menu{
private:

    SDL_Rect rect;
    TTF_Font* font;
    SDL_Texture* text;
    SDL_Color color1 = {255, 255, 255, 255};
    SDL_Color color2 = {255, 0, 0, 255};
    SDL_Color color3 = {255, 255, 0};
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    int x1, x2;

public:
    void Write_menu(const char* s, int x, int y, int h, int w, SDL_Color color){
        font = Object::loadFont("Text_game/Oswald-Medium.ttf", 100);

        rect.x = x; rect.y = y;
        rect.h = h; rect.w = w;
        text = Object::renderText(s, font, color);
        SDL_RenderCopy(Game::renderer, text, NULL, &rect);
        SDL_RenderPresent(Game::renderer);
    }
    bool Menu3 = false;
    bool Menu2=false;
    bool Menu1=false;
    bool Menu_back = true;
    bool Menu1_(){

        string s1, s2;
        ifstream file("Score.txt");

        file >> x1 >> x2;
        file.close();
        cout << endl << x1 << " " << x2;
        s1 = "High Score: " + to_string(x1);
        SDL_Event event;
        int x, y;
        while(true){



            if(!Menu1){
                SDL_RenderCopy(Game::renderer, Graphics::loadTexture("Assets/Menu_game.png"), NULL, NULL);
                SDL_RenderPresent(Game::renderer);

            }


            if(!Menu2) Menu_back = true;
            while (Menu_back) {
                SDL_GetMouseState(&x, &y);
                if(x>=30 && x <= 410){
                    if(y >= 240 && y <= 300) Write_menu("Play", 150, 240, 50, 150, color2);
                    else Write_menu("Play", 150, 240, 50, 150, color1);
                    if(y >= 340 && y <= 400) Write_menu ("About Us", 80, 340, 50, 300, color2);
                    else  Write_menu("About Us", 80, 340, 50, 300, color1);
                    if(y >= 430 && y<= 490) Write_menu("Version", 120, 440, 50, 200, color2);
                    else{
                        Write_menu("Version", 120, 440, 50, 200, color1);
                    }
                }
                else{
                    Write_menu("About Us", 80, 340, 50, 300, color1);
                    Write_menu("Version", 120, 440, 50, 200, color1);
                    Write_menu("Play", 150, 240, 50, 150, color1);
                }
                SDL_PollEvent(&event);
                switch (event.type) {
                    case SDL_MOUSEBUTTONDOWN:
                        if(x >= 30 && x <= 410 && y >= 240 && y <= 300){
                            Menu2= true;
                            if(Menu2){
                                SDL_RenderCopy(Game::renderer, Graphics::loadTexture("Assets/Choose_door.png"), NULL, NULL);
                                SDL_RenderPresent(Game::renderer);

                            }
                            while(Menu2){
                                SDL_Event p;
                                int m, n;
                                SDL_GetMouseState(&m, &n);
                                cout << m << " " << n << endl;
                                Write_menu("Press the spacebar to jump and P to pause!!!", 230, 90, 50, 500, color1);
                                if(x2) Write_menu(s1.c_str(), 45, 176, 60, 130, color3);
                                else  Write_menu(s1.c_str(), 45, 176, 60, 130, color1);

                                if(m >= 45 && m <= 275 && n >= 225 && n <= 300) Write_menu("Door 1", 110, 225, 80, 100, color2);
                                else Write_menu("Door 1", 110, 225, 80, 100, color1);
                                if(m >= 670 && m <= 900 && n >= 525 && n <= 600) Write_menu("Back", 740, 525, 80, 100, color2);
                                else Write_menu("Back", 740, 525, 80, 100, color1);
                                SDL_PollEvent(&p);
                                switch (p.type) {
                                    case SDL_MOUSEBUTTONDOWN:
                                        if(m >= 45 && m <= 275 && n >= 225 && n <= 300){
                                            Menu1 = true;
                                            return 1;
                                        }
                                        if(m >= 670 && m <= 900 && n >= 525 && n <= 600){
                                            Menu2 = false;
                                            Menu_back = false;
                                        }
                                }
                            }
                        }
                }
            }
        }
    }

    bool Menu2_(){
        bool Menu2_1=false;
        bool Menu2_2=false;
        bool Menu2_3=false;
        bool Menu2_back=true;
        SDL_Event event;
        int x, y;
        while(true){
            int i_score = Game::score;
            string s = to_string(i_score);
            if(!Menu2_1){

            if(!Object::Get_stars){
                SDL_RenderCopy(Game::renderer, Graphics::loadTexture("Assets/You_win_gold.png"), NULL, NULL);
                SDL_RenderPresent(Game::renderer);
                Write_menu(s.c_str(), 430, 390, 60, 100, color2);
            }
            else{
                SDL_RenderCopy(Game::renderer, Graphics::loadTexture("Assets/You_win_nomal.png"), NULL, NULL);
                SDL_RenderPresent(Game::renderer);
                Write_menu(s.c_str(), 430, 390, 60, 100, color2);
            }
            }
            if(!Menu2_2) Menu_back=true;
            while(true){
              //  cerr << x << " " << y << endl;
                SDL_GetMouseState(&x, &y);
                SDL_PollEvent(&event);
                if(x>=40 && x<=385 && y>=450 && y <= 515) Write_menu("Menu", 150, 440, 80, 120, color2);
                else{
                    Write_menu("Menu", 150, 440, 80, 120, color1);
                }
                if(x>=580 && x<=930 && y>= 450 && y <= 515) Write_menu("Next Door", 700, 440, 80, 140, color2);
                else{

                    Write_menu("Next Door", 700, 440, 80, 140, color1);
                }

                switch (event.type) {
                    case SDL_MOUSEBUTTONDOWN:
                        if(x>=40 && x<=385 && y>=450 && y <= 515){
                            Menu2 = false;
                            Menu_back = false;
                            Menu1 = false;
                            Game::starst = true;
                            Game::end_game = false;
                         //   Object::Get_stars = true;
                            return 1;
                        }

                }

            }
        }
    }
    void Menu_pause(bool &Pause){
        if (keyState[SDL_SCANCODE_P]) Pause = true;
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0 || Pause == true){
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_c)
                    {
                        Pause = false;
                        return;

                    }
                if (event.key.keysym.sym == SDLK_m){
                        cout << endl << "here";
                        Menu2 = false;
                        Menu_back = false;
                        Menu1 = false;
                        Game::starst = true;
                        Game::end_game = false;
                        Pause = false;
                        Object::collide = true;
                        Game::score = 100;
                        return;

                }
            }
            if(Pause == true){
                SDL_RenderCopy(Game::renderer, Graphics::loadTexture("Assets/Pause.png"), NULL, NULL);
                SDL_RenderPresent(Game::renderer);
            }


        }
        return;
    }
    void Menu_score(){
        if(Game::high_score < Game::score) Game::high_score = Game::score;
        if(Game::high_score > x1){
            ofstream file("Score.txt");
            cout << Game::score;
            if(!Object::Get_stars){
                file << Game::high_score << " " << 1;
            }
            else {
                file << Game::high_score << " " << 0;
            }
            file.close();

        }
    }

};
#endif // Menu_h
