//  Copyright 2022 Anthony Tossell
#include "../include/GameRectangle.h"

#include <SDL2/SDL.h>

GameRectangle::GameRectangle(SDL_Window* w) {
    surface = SDL_GetWindowSurface(w);
}

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

void GameRectangle::setColour(int r, int g, int b) {
    colour.red = r;
    colour.blue = b;
    colour.green = g;
}

void GameRectangle::draw(SDL_Surface* s) {
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, colour.red, colour.green, colour.blue));
    SDL_BlitSurface(s, NULL, surface, NULL);
}
