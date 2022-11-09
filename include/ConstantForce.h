//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_CONSTANTFORCE_H_
#define INCLUDE_CONSTANTFORCE_H_

#include "IForceable.h"
#include "IAccelerateable.h"

class ConstantForce : public IForceable {
 private:
    const float X_FORCE = 0;
    const float Y_FORCE = 0;
 public:
    static const float CONST_FORCE_NONE;
    static const float CONST_FORCE_GRAVITY;

    ConstantForce(float x, float y) : X_FORCE{x}, Y_FORCE{y} {}

    void act(IAccelerateable* obj);
};

#endif  // INCLUDE_CONSTANTFORCE_H_
