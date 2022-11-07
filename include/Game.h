//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include <SDL2/SDL.h>
#include <vector>

#include "IDrawable.h"
#include "KeyboardInputHandler.h"

class Game {
 private:
    std::vector<IDrawable*> drawables;

    void init();
    void draw();
    void run();
    void close();
 public:
    const int SCREEN_WIDTH = 500;
    const int SCREEN_HEIGHT = 500;

    const int LOOP_DELAY = 15;

    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;
    SDL_Renderer* renderer = NULL;

    void start();
};

#endif  // INCLUDE_GAME_H_
