#ifndef Menu_h
#define Menu_h
#include "Game.h"
#include "Graphics.h"
#include "Object.h"

class Menu{
private:

    SDL_Rect rect;
    TTF_Font* font;
    SDL_Texture* text;
    SDL_Color color1 = {255, 255, 255, 255};
    SDL_Color color2 = {255, 0, 0, 255};
public:
    void Write_menu(const char* s, int x, int y, int h, int w, SDL_Color color){
        font = Object::loadFont("Text_game/Merriweather-LightItalic.ttf", 100);

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
            cerr << x << ", " << y << endl;
            if(x>=30 && x <= 410){
                if(y >= 240 && y <= 300) Write_menu("Play", 150, 240, 50, 150, color2);
                else if(y >= 340 && y <= 400) Write_menu ("About Us", 80, 340, 50, 300, color2);
                else if(y >= 430 && y<= 490) Write_menu("Version", 120, 440, 50, 200, color2);
                else{
                    Write_menu("Play", 150, 240, 50, 150, color1);
                    Write_menu("About Us", 80, 340, 50, 300, color1);
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
                            cerr << m << ", " << n << endl;
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
};
#endif // Menu_h
