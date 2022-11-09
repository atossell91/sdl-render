//  Copyright 2022 Anthony Tossell
#include "../include/ConstantForce.h"

#include "IAccelerateable.h"

const float ConstantForce::CONST_FORCE_NONE = 0.0;
const float ConstantForce::CONST_FORCE_GRAVITY = 0.1635;

void ConstantForce::act(IAccelerateable* obj) {
    obj->modifySpeedX(X_FORCE);
    obj->modifySpeedY(Y_FORCE);
}
