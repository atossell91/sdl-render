//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_GAMERECTANGLE_H_
#define INCLUDE_GAMERECTANGLE_H_

#include <SDL2/SDL.h>

#include "Colour.h"
#include "IDrawable.h"

class GameRectangle : public IDrawable {
 private:
    SDL_Texture* texture;
    SDL_Surface* surface;
    SDL_Rect r;
    Colour colour;
 public:
    GameRectangle(SDL_Window* w);
    ~GameRectangle();
    void setWidth(int width);
    void setHeight(int height);
    void setX(int x);
    void setY(int y);
    void setColour(int red, int green, int blue);
    void draw(SDL_Surface* mainSurface);
};

#endif  // INCLUDE_GAMERECTANGLE_H_
