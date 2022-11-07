//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_INPUTHANDLER_H_
#define INCLUDE_INPUTHANDLER_H_

struct InputVector {
    float xMagnitude = 0.0;
    float YMagnitude = 0.0;
};

class InputHandler {
 private:
 public:
    virtual void updateInputState() = 0;
    virtual float getComponentX() = 0;
    virtual float getComponentY() = 0;
};

#endif  // INCLUDE_INPUTHANDLER_H_
