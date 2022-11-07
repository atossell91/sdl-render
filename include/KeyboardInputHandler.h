//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_KEYBOARDINPUTHANDLER_H_
#define INCLUDE_KEYBOARDINPUTHANDLER_H_

#include <SDL2/SDL.h>

#include "InputHandler.h"
#include "KeyboardDeviceHandler.h"

class KeyboardInputHandler : public InputHandler {
 private:
    KeyboardDeviceHandler* driver;
 public:
    const SDL_Scancode UpKey;
    const SDL_Scancode DownKey;
    const SDL_Scancode LeftKey;
    const SDL_Scancode RightKey;

    enum EnumHorizontalInput {Left, HNone, Right};
    enum EnumVerticalInput {Up, VNone, Down};

    EnumHorizontalInput HorizontalInputState = EnumHorizontalInput::HNone;
    EnumVerticalInput VerticalInputState = EnumVerticalInput::VNone;

    KeyboardInputHandler(KeyboardDeviceHandler* d, SDL_Scancode up, SDL_Scancode down,
    SDL_Scancode left, SDL_Scancode right) : driver{d}, UpKey{up}, DownKey{down},
    LeftKey{left}, RightKey{right} {}

    void updateInputState();
    float getComponentX();
    float getComponentY();
};

#endif  // INCLUDE_KEYBOARDINPUTHANDLER_H_
