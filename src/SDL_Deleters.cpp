//  Copyright 2022 Anthony Tossell
#include "../include/SDL_Deleters.h"

#include <SDL2/SDL.h>
#include <iostream>

void SDL_Renderer_Deleter::operator()(SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
}

void SDL_Window_Deleter::operator()(SDL_Window* window) {
    SDL_DestroyWindow(window);
}

void SDL_Surface_Deleter::operator()(SDL_Surface* surface) {
    SDL_FreeSurface(surface);
}
