#include "Object.h"
#include "Graphics.h"
#include<bits/stdc++.h>
using namespace std;
Object::Object() {};

Object::~Object() {}

Object::Object(const char* fileDir, int x, int y, double scale, vector<pair<int,int>> &v) {
    objTexture = Graphics::loadTexture(fileDir);

    for(auto x:v) collision.push_back(x);

    destRect.x = x;
    destRect.y = y;
    destRect.w = destRect.h = 64*scale;
}

const Uint8* keyState = SDL_GetKeyboardState(NULL);
void Object::attack(int x, int y){
    destRect.x = x;
}
void Object::roto()
{
    angle += pi * 2.048;
    Graphics::Draw(objTexture, src, destRect, angle);
}

void Object::Check_ground(){
    bool check = false;
    for(int i = 2; i < collision.size();i++){
            //sua destRect.x +32
        if( i <= 1) continue;
        if ((destRect.x + 32 >= collision[i].first) && (destRect.x  <= collision[i].first + 64)
            && (destRect.y + 30 <= collision[i].second))

        {

            Ground_height = collision[i].second;
            check = true;
            return;
        }
    }
    if (!check)
    {
        //ontheground = false;
        Ground_height = 600;
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
    if (destRect.x + destRect.w >= 800 || destRect.x < 0)
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

   bool collide =false;


   for(int i = 0; i < collision.size();i++){


        if ((destRect.x + 32 >= collision[i].first + 5) && (destRect.x + 32 <= collision[i].first + 64 - 5)
            && (destRect.y > collision[i].second + 10) && (destRect.y <= collision[i].second + 64))
        {
            cout << "yes1" << endl;
            collide = true;
            break;

        }

        else if ((destRect.x + 32 >= collision[i].first + 5) && (destRect.x + 32 <= collision[i].first + 64 - 5)
            && (destRect.y + 32 > collision[i].second + 10) && (destRect.y + 32 <= collision[i].second + 64))
        {
            cout << "yes2" << endl;
            collide = true;
            break;

        }

        else if ((destRect.x >= collision[i].first + 5) && (destRect.x <= collision[i].first + 64 - 5)
            && (destRect.y > collision[i].second + 10) && (destRect.y <= collision[i].second + 64))
        {
            cout << "yes3" << endl;
            collide = true;
            break;

        }

        else if ((destRect.x >= collision[i].first + 5) && (destRect.x <= collision[i].first + 64 - 5)
            && (destRect.y + 32 > collision[i].second + 10) && (destRect.y + 32 <= collision[i].second + 64))
        {
            cout << "yes4" << endl;
            collide = true;
            break;

        }

    }

    if(collide)
    {
        destRect.x = 0;
        destRect.y = 600 - 32;
        ontheground = true;
        isJumping = false;
    }
    else
    {
        destRect.x += velocity.first;
        destRect.y += velocity.second;

    }


}

void Object::render() {
    Graphics::Draw(objTexture, src, destRect, angle);
}
