#include "Object.h"
#include "Graphics.h"
#include "Map.h"
#include<bits/stdc++.h>
using namespace std;
Object::Object() {};

Object::~Object() {}

Object::Object(const char* fileDir, int x, int y, double scale) {
    objTexture = Graphics::loadTexture(fileDir);

    destRect.x = x;
    destRect.y = y;
    destRect.w = destRect.h = 64*scale;
}


const Uint8* keyState = SDL_GetKeyboardState(NULL);
void Object::attack_x(){
    Graphics::Draw(objTexture, destRect, angle);

    destRect.y = 450 - 64*2;
    destRect.x += 4;
    if(destRect.x >= 800) destRect.x = 0;





}
void Object::roto()
{
    angle += pi * 2.048;
    Graphics::Draw(objTexture, destRect, angle);
}
vector <int> Object::block;
void Object::Check_ground(){
    bool check = false;
    for(int i = 0; i < Game::collision.size();i++){
            //sua destRect.x +32
        bool check_block = false;
        for(int j = 0; j < (int) block.size(); j++ ){
            if(i == block[j]){
                check_block = true;
                break;
            }
        }
        if ((destRect.x + 32 >= Game::collision[i].first) && (destRect.x  <= Game::collision[i].first + 32)
            && (destRect.y + 25 <= Game::collision[i].second) && (check_block))

        {

            Ground_height = Game::collision[i].second;
            check = true;
            return;
        }
        check_block = false;
    }
    if (!check)
    {
        //ontheground = false;
        Ground_height = 640;
    }

}

void Object::Gravity(){


    if(!ontheground){
            velocity.second = 3;
            angle += pi * 2.048;
    }
    else{
            velocity.second = 0;
            angle = 0.0f;
    }
}
void Object::update() {
    if (destRect.x + destRect.w >= 960 || destRect.x < 0)
        velocity.first *= -1;

// check nhay
    Check_ground();
    if( destRect.y +32 >= Ground_height  ){
            destRect.y  = Ground_height - 33;
            ontheground = true;
    }else if (destRect.y + 33 < Ground_height)
    {

        ontheground = false;
    }

    if(keyState[SDL_SCANCODE_SPACE] && ontheground){
        ontheground = false;
        jumpStart = destRect.y;
        isJumping = true;
    }

    if( isJumping )
    {
        if(destRect.y >= jumpStart - jumpHeight){
            destRect.y -=6;

        }else{
            isJumping = false;
        }
    }
    Gravity();

// check va cham



    if(collide)
    {
        destRect.x = 0;
        destRect.y = 960 - 32;
        ontheground = true;
        isJumping = false;
        collide = false;
    }
    else
    {
        destRect.x += velocity.first;
        destRect.y += velocity.second;

    }


    if(destRect.y <= 450 - 64){
            shot = true;
            cout << "now" << endl;
    }
}

void Object::render() {
    Graphics::Draw(objTexture, destRect, angle);
}
SDL_Texture* Object::renderText(const char* text,
                            TTF_Font* font, SDL_Color textColor)
    {
        SDL_Surface* textSurface =
                TTF_RenderText_Solid( font, text, textColor );
        if( textSurface == nullptr ) {

            return nullptr;
        }

        SDL_Texture* texture =
                SDL_CreateTextureFromSurface( Game::renderer, textSurface );
        if( texture == nullptr ) {

        }
        SDL_FreeSurface( textSurface );
        return texture;
    }
    TTF_Font* Object::loadFont(const char* path, int size)
    {
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            return nullptr;
        }
    }
void Object::write(const char* s)
{
    font = loadFont("Text_game/Merriweather-LightItalic.ttf", 100);
    SDL_Color color = {255, 0, 0, 255};
    text = renderText( s,font,color );
    SDL_RenderCopy(Game::renderer, text, NULL, &destRect);
}
