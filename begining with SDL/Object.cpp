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


// check mat dat
bool Object::isGrounded() {
    if (destRect.y >= 600 - 64*0.5) {

        destRect.y = 600 - 64*0.5;
        return true;
    }
    return false;
}


void Object::update() {

    if (destRect.x + destRect.w >= 800 || destRect.x < 0)
        velocity.first *= -1;

// check do cao
    for(int i = 0; i < collision.size();i++){
        if ((destRect.x + 32 >= collision[i].first) && (destRect.x + 32 <= collision[i].first + 64)
            && (destRect.y + 32 <= collision[i].second) )
        {
            do_cao_mat_dat = 600 - collision[i].second;
            break;
        }
    }



// check va cham
   bool collide =false;
//   cout << collision.size() << "D" << endl;
   for(int i = 0; i < collision.size();i++){
//        cout << collision[i].first<< " " << collision[i].second << " " << i << endl;

        if ((destRect.x + 32 >= collision[i].first) && (destRect.x + 32 <= collision[i].first + 64)
            && (destRect.y > collision[i].second) && (destRect.y <= collision[i].second + 64))
        {
            collide = true;
            break;

        }
        if ((destRect.x + 32 >= collision[i].first) && (destRect.x + 32 <= collision[i].first + 64)
            && (destRect.y + 32 > collision[i].second) && (destRect.y + 32 <= collision[i].second + 64))
        {
            collide = true;
            break;

        }

        if ((destRect.x >= collision[i].first) && (destRect.x <= collision[i].first + 64)
            && (destRect.y > collision[i].second) && (destRect.y <= collision[i].second + 64))
        {
            collide = true;
            break;

        }

        if ((destRect.x >= collision[i].first) && (destRect.x <= collision[i].first + 64)
            && (destRect.y + 32 > collision[i].second) && (destRect.y + 32 <= collision[i].second + 64))
        {
            collide = true;
            break;

        }

    }
    if(collide)
    {
        destRect.x = 0;
        destRect.y = 600 - 32;
    }
    else
    {
        destRect.x += velocity.first;
        destRect.y += velocity.second;

    }

// check nhay

     if (keyState[SDL_SCANCODE_SPACE] && !isJumping && isGrounded()) {
        cout << "yes" << endl;
        jumpStart = destRect.y; // fix here
        velocity.second = -3; // toc do roi
        jump -= velocity.second;
        jumpLimit = destRect.y -  jumpHeight;
        isJumping = true;
    }

    if (!isJumping) {
        angle = 0.0f;
    }

    // std::cout << jumpStart << " " << destRect.x << " " << jumpHeight << "\n";

    if (jumpStart - destRect.y >= jumpHeight) {
        velocity.second = 5;
    }

    if (isJumping) {
        angle += pi * 2.048;
        if (destRect.y > jumpStart) {
            isJumping = false;
            velocity.second = 0;
        }
    }


}

void Object::render() {
    Graphics::Draw(objTexture, src, destRect, angle);
}
