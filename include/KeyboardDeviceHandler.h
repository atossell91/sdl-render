//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_KEYBOARDDEVICEHANDLER_H_
#define INCLUDE_KEYBOARDDEVICEHANDLER_H_

#include <SDL2/SDL.h>

class KeyboardDeviceHandler {
 private:
    const Uint8* state;
 public:
    const void UpdateState();
    const Uint8* getState();
};

#endif  // INCLUDE_KEYBOARDDEVICEHANDLER_H_
