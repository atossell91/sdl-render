//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_IDRAWABLE_H_
#define INCLUDE_IDRAWABLE_H_

#include <SDL2/SDL.h>

class IDrawable {
 private:
 public:
    virtual void draw(SDL_Renderer* renderer) = 0;
};

#endif  // INCLUDE_IDRAWABLE_H_
