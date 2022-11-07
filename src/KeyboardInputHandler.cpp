//  Copyright 2022 Anthony Tossell
#include "../include/KeyboardInputHandler.h"

#include <SDL2/SDL.h>

void KeyboardInputHandler::updateInputState() {
    if (driver->getState()[UpKey]) {
        VerticalInputState = EnumVerticalInput::Up;
    }
    else if (driver->getState()[DownKey]) {
        VerticalInputState = EnumVerticalInput::Down;
    }
    else {
        VerticalInputState = EnumVerticalInput::VNone;
    }

    if (driver->getState()[LeftKey]) {
        HorizontalInputState = EnumHorizontalInput::Left;
    }
    else if (driver->getState()[RightKey]) {
        HorizontalInputState = EnumHorizontalInput::Right;
    }
    else {
        HorizontalInputState = EnumHorizontalInput::HNone;
    }
}

float KeyboardInputHandler::getComponentX() {
    return static_cast<float>(HorizontalInputState-1);
}

float KeyboardInputHandler::getComponentY() {
    return static_cast<float>(VerticalInputState-1);
}
