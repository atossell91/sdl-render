//  Copyright 2022 Anthony Tossell
#include "../include/Game.h"

#include <SDL2/SDL.h>

#include "GameRectangle.h"

void Game::init() {
    //  Initialize SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    //  Create the window
    window = SDL_CreateWindow("Renderer", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    //  Create a surface from the window
    surface = SDL_GetWindowSurface(window);
}

void Game::draw() {
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 150, 150, 150));
    for (auto d : drawables) {
        d->draw(surface);
    }
    SDL_UpdateWindowSurface(window);    
}

void Game::run() {
    GameRectangle g(window);
    g.setWidth(100);
    g.setHeight(100);
    g.setX(300);
    g.setY(300);
    drawables.push_back(&g);

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        draw();
    }
}

void Game::close() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::start() {
    init();
    run();
    close();
}
