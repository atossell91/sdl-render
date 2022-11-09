//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_JOYSTICKINPUTHANDLER_H_
#define INCLUDE_JOYSTICKINPUTHANDLER_H_

#include <SDL2/SDL.h>

#include "InputHandler.h"

class JoystickInputHandler : public InputHandler {
 private:
    SDL_Joystick* joystick = NULL;
    Sint16 xAxis = 0;
    Sint16 yAxis = 0;

    enum EnumAxisNum {axisX, axisY};
 public:
    const int DEADZONE = 1000;
    const int MAX_VAL = 32768;

    JoystickInputHandler() : JoystickInputHandler(0) {}
    JoystickInputHandler(int joystickNum);

    float getJoystickComponent(Sint16 axis);
    void updateInputState();
    float getComponentX();
    float getComponentY();
};

#endif  // INCLUDE_JOYSTICKINPUTHANDLER_H_
