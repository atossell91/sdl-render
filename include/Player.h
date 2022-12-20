//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <SDL2/SDL.h>
#include <vector>
#include <memory>

#include "IDrawable.h"
#include "KeyboardInputHandler.h"
#include "IUpdateable.h"
#include "IAccelerateable.h"
#include "IForceable.h"
#include "ICollidable.h"

class Player : public IDrawable, public IUpdateable, public IAccelerateable {
 private:
    SDL_Rect r;
    std::shared_ptr<InputHandler> inputHandler = NULL;
    float speedX = 0.0;
    float speedY = 0.0;
   std::vector<std::shared_ptr<IForceable>> forces;
   std::vector<std::shared_ptr<ICollidable>> colliders;

 public:
    const int MOVEMENT_SPEED = 10;
    Player();
    
    //  Input oject?
    void setInputHandler(std::shared_ptr<InputHandler> handler);
    void updateInputState();
    
    //  Mover object?
    void directMove();
    void move();
    
    //  Single and multiple force objects
    //  Also, should addforce and apply forces have their own interface?
    //  Should they use the IAcceleratable interface, or a different one?
    void addForce(std::shared_ptr<IForceable> force);
    void applyForces();
    void modifySpeedX(float spd);
    void modifySpeedY(float spd);

    void draw(SDL_Renderer* rend);
    void update();
};

#endif  // INCLUDE_PLAYER_H_

/*
sruct dimension
   int loc
   int size

int maxDim = 3
dimension dims[maxdim]

bool inRange(val, lower, upper)
   lower <= val <= upper

bool isInside(dimension)
   for (dimension d : dims) {
      inRange(d.loc, )
   }
*/