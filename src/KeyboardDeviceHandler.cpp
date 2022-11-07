//  Copyright 2022 Anthony Tossell
#include "../include/KeyboardDeviceHandler.h"

#include <SDL2/SDL.h>

const void KeyboardDeviceHandler::UpdateState() {
    state = SDL_GetKeyboardState(NULL);
}

const Uint8* KeyboardDeviceHandler::getState() {
    return state;
}
