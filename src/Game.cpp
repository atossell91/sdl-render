//  Copyright 2022 Anthony Tossell
#include "../include/Game.h"

#include <SDL2/SDL.h>
#include <thread>
#include <chrono>
#include <iostream>

#include "KeyboardInputHandler.h"
#include "Player.h"
#include "KeyboardDeviceHandler.h"
#include "JoystickInputHandler.h"
#include "IForceable.h"
#include "ConstantForce.h"

void Game::init() {
    //  Initialize SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK);

    //  Create the window
    window = SDL_CreateWindow("Renderer", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //  Create a surface from the window
    //surface = SDL_GetWindowSurface(window);
}

void Game::draw() {
    //SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 125, 125, 125));
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    for (auto d : drawables) {
        d->draw(renderer);
    }
    SDL_RenderPresent(renderer);
    //SDL_UpdateWindowSurface(window);
}

void Game::run() {
    KeyboardDeviceHandler driver;
    KeyboardInputHandler handler(&driver, SDL_SCANCODE_W, SDL_SCANCODE_S,
    SDL_SCANCODE_A, SDL_SCANCODE_D);

    JoystickInputHandler joystickInput;
    Player p;
    drawables.push_back(&p);
    p.setInputHandler(&joystickInput);
    
    KeyboardInputHandler handler2(&driver, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN,
    SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT);
    Player p2;
    drawables.push_back(&p2);
    p2.setInputHandler(&handler2);
    ConstantForce gravity(ConstantForce::CONST_FORCE_NONE,
    ConstantForce::CONST_FORCE_GRAVITY);
    p2.addForce(&gravity);
    

    int amt = 5;
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        driver.UpdateState();
        p.update();
        p2.update();
        draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(LOOP_DELAY));
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
