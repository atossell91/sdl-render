//  Copyright 2022 Anthony Tossell
#include "../include/Player.h"

#include <SDL2/SDL.h>
#include <memory>

Player::Player() {
    r.x = 0;
    r.y = 0;
    r.w = 100;
    r.h = 100;
}

void Player::addForce(std::shared_ptr<IForceable> force) {
    forces.push_back(force);
}

void Player::applyForces() {
    for (auto f :  forces) {
        f->act(this);
    }
}

void Player::setInputHandler(std::shared_ptr<InputHandler> handler) {
    if (handler == NULL) return;
    inputHandler = handler;
}

void Player::updateInputState() {
    if (inputHandler != NULL) {
        inputHandler->updateInputState();
    }
}

void Player::directMove() {
    if (inputHandler != NULL) {
        float xAmt = inputHandler->getComponentX();
        float yAmt = inputHandler->getComponentY();
        r.x += xAmt*MOVEMENT_SPEED;
        r.y += yAmt*MOVEMENT_SPEED;
    }
}

void Player::move() {
    r.x += speedX;
    r.y += speedY;
}

void Player::modifySpeedX(float spd) {
    speedX += spd;
}

void Player::modifySpeedY(float spd) {
    speedY += spd;
}

void Player::draw(SDL_Renderer* rend) {
    SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
    SDL_RenderFillRect(rend, &r);
}

void Player::update() {
    updateInputState();
    directMove();

    applyForces();
    
    move();
}
