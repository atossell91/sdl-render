//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include <SDL2/SDL.h>
#include <vector>

#include "IDrawable.h"
#include "KeyboardInputHandler.h"
#include "SDL_Deleters.h"

class Game {
 private:
    std::vector<IDrawable*> drawables;

    void init();

    void input();
    void update();
    void draw();
    
    void run();
    void close();
 public:
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;

    const int LOOP_DELAY = 15;

    std::unique_ptr<SDL_Window, SDL_Window_Deleter> window = NULL;
    std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter> renderer = NULL;

    void start();
};

#endif  // INCLUDE_GAME_H_
