//  Copyright 2022 Anthony Tossell
#include "../include/JoystickInputHandler.h"

#include <SDL2/SDL.h>
#include <iostream>

JoystickInputHandler::JoystickInputHandler(int j) {
    if (SDL_NumJoysticks() < 1) {
        std::cout << "No joysticks found" << std::endl;
    }
    else {
        std::cout << "Found " << SDL_NumJoysticks() << " joysticks." << std::endl;
        joystick = SDL_JoystickOpen(j);
    }
}

void JoystickInputHandler::updateInputState() {
    xAxis = SDL_JoystickGetAxis(joystick, axisX);
    yAxis = SDL_JoystickGetAxis(joystick, axisY);
}

float JoystickInputHandler::getJoystickComponent(Sint16 axis) {
    if (abs(axis) < DEADZONE) {
        return 0.0;
    }
    return static_cast<float>(axis - DEADZONE) / static_cast<float>(MAX_VAL - DEADZONE);
}

float JoystickInputHandler::getComponentX() {
    return getJoystickComponent(xAxis);
}

float JoystickInputHandler::getComponentY() {
    return getJoystickComponent(yAxis);
}
