//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_IFORCEABLE_H_
#define INCLUDE_IFORCEABLE_H_

#include "IAccelerateable.h"

class IForceable {
 private:
 public:
    virtual void act(IAccelerateable* obj) = 0;
};

#endif  // INCLUDE_IFORCEABLE_H_
