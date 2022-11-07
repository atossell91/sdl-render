//  Copyright 2022 Anthony Tossell
#include "../include/Player.h"

#include <SDL2/SDL.h>

Player::Player() {
    gameRectangle.setX(0);
    gameRectangle.setY(0);
    gameRectangle.setWidth(100);
    gameRectangle.setHeight(100);
}

void Player::setInputHandler(InputHandler* handler) {
    if (handler == NULL) return;
    inputHandler = handler;
}

void Player::updateInputState() {
    if (inputHandler != NULL) {
        inputHandler->updateInputState();
    }
}

void Player::move() {
    if (inputHandler != NULL) {
        float xAmt = inputHandler->getComponentX();
        float yAmt = inputHandler->getComponentY();
        gameRectangle.moveX(xAmt*MOVEMENT_SPEED);
        gameRectangle.moveY(yAmt*MOVEMENT_SPEED);
    }
}

void Player::draw(SDL_Renderer* rend) {
    gameRectangle.draw(rend);
}
