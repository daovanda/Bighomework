#ifndef _MAP__H
#define _MAP__h
#include "Object.h"
#include "Game.h"
#include "Graphics.h"
#include<bits/stdc++.h>

using namespace std;
const int SIZE = 32;
static double rad = 0;
class Map{
private:
    int f = 0;
    int tile[20][30];
    std::vector<SDL_Texture*> anh;
    SDL_Rect rect;
public:
    void loadMap()
    {
        ifstream file("map.txt");
        for (int i=0; i < 20; i++)
        {
            for (int j=0; j < 30; j++)
            {
                file >> tile[i][j];

                if (tile[i][j] > 0)
                {
                    if(tile[i][j] == 2)
                    {
                        Object::block.push_back(f);
                        cout << f << " ";
                    }
                    f++;
                    Game::collision.push_back(make_pair(j * SIZE, i * SIZE));
                }

            }
        }
        file.close();
        string s = "";
        for (int i=1; i <= 3; i++)
        {
            s = "Assets/" + to_string(i) + ".png";
            anh.push_back(IMG_LoadTexture(Game::renderer, s.c_str()));
        }
        rect.w = rect.h =32;
    }
    void renderMap()
    {
        for (int i=0; i < 20; i++)
        {
            for (int j=0; j < 30; j++)
            {
                if (tile[i][j] > 0)
                {
                    rect.x = j * SIZE;
                    rect.y = i * SIZE;

                    if (tile[i][j] == 3) {
                        Graphics::Draw(anh[tile[i][j] - 1], rect, rad);
                        rad += (2.048 / 3);
                        continue;
                    }

                    SDL_RenderCopy(Game::renderer, anh[tile[i][j] - 1],NULL, &rect);
                    //SDL_RenderPresent(Game::renderer);
                }
            }
        }



        freopen("CON", "w", stdout);

    }
};


#endif // _MAP__H

