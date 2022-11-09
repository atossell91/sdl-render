//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <SDL2/SDL.h>
#include <vector>

#include "IDrawable.h"
#include "KeyboardInputHandler.h"
#include "IUpdateable.h"
#include "IAccelerateable.h"
#include "IForceable.h"

class Player : public IDrawable, public IUpdateable, public IAccelerateable {
 private:
    SDL_Rect r;
    InputHandler* inputHandler = NULL;
    float speedX = 0.0;
    float speedY = 0.0;
   std::vector<IForceable*> forces;
 public:
    const int MOVEMENT_SPEED = 10;
    Player();
    
    //  Input oject?
    void setInputHandler(InputHandler* handler);
    void updateInputState();
    
    //  Mover object?
    void directMove();
    void move();
    
    //  Single and multiple force objects
    //  Also, should addforce and apply forces have their own interface?
    //  Should they use the IAcceleratable interface, or a different one?
    void addForce(IForceable* force);
    void applyForces();
    void modifySpeedX(float spd);
    void modifySpeedY(float spd);

    void draw(SDL_Renderer* rend);
    void update();
};

#endif  // INCLUDE_PLAYER_H_
