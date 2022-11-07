//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <SDL2/SDL.h>

#include "IDrawable.h"
#include "KeyboardInputHandler.h"
#include "GameRectangle.h"

class Player : public IDrawable {
 private:
    InputHandler* inputHandler = NULL;
    GameRectangle gameRectangle;
 public:
    const int MOVEMENT_SPEED = 10;
    Player();
    void setInputHandler(InputHandler* handler);
    void updateInputState();
    void move();
    void draw(SDL_Renderer* rend);
};

#endif  // INCLUDE_PLAYER_H_
