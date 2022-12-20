//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_SDL_DELETERS_H_
#define INCLUDE_SDL_DELETERS_H_

#include <SDL2/SDL.h>

struct SDL_Renderer_Deleter {
    void operator()(SDL_Renderer* renderer);
};

struct SDL_Window_Deleter {
    void operator()(SDL_Window* window);
};

struct SDL_Surface_Deleter {
    void operator()(SDL_Surface* surface);
};


#endif  // INCLUDE_SDL_DELETERS_H_
