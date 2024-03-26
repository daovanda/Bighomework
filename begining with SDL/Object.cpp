#include "Object.h"
#include "Graphics.h"

Object::Object() {};

Object::~Object() {}

Object::Object(const char* fileDir, int x, int y) {
    objTexture = Graphics::loadTexture(fileDir);
    destRect.x = x;
    destRect.y = y;
    destRect.w = destRect.h = 64;
}

const Uint8* keyState = SDL_GetKeyboardState(NULL);

bool Object::isGrounded() {
    if (destRect.y >= 600 - 64) {
        destRect.y = 600 - 64;
        std::cout << "Yes\n";
        return true;
    }
    return false;
}

void Object::update() {
    // if (destRect.y >= 600 - 64) destRect.y = 600 - 64;

    if (destRect.x + destRect.w >= 800 || destRect.x < 0)
        velocity.first *= -1;

    if (keyState[SDL_SCANCODE_SPACE] && !isJumping && isGrounded()) {
        jumpStart = destRect.y;
        velocity.second = -5;
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

    destRect.x += velocity.first;
    destRect.y += velocity.second;
}

void Object::render() {
    Graphics::Draw(objTexture, src, destRect, angle);
}
