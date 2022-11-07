//  Copyright 2022 Anthony Tossell
#include "../include/GameRectangle.h"

#include <SDL2/SDL.h>
#include <iostream>

GameRectangle::GameRectangle() {}

GameRectangle::~GameRectangle() {
    if (surface != NULL) {
        SDL_FreeSurface(surface);
    }
}

void GameRectangle::setWidth(int w) {
    r.w = w;
}

void GameRectangle::setHeight(int h) {
    r.h = h;
}

void GameRectangle::setX(int x) {
    r.x = x;
}

void GameRectangle::setY(int y) {
    r.y = y;
}

void GameRectangle::moveX(int amt) {
    r.x += amt;
}

void GameRectangle::moveY(int amt) {
    r.y += amt;
}

void GameRectangle::setColour(int r, int g, int b) {
    colour.red = r;
    colour.blue = b;
    colour.green = g;
}

void GameRectangle::draw(SDL_Renderer* rend) {
    SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
    SDL_RenderFillRect(rend, &r);
}
