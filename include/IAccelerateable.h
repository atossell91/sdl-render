//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_IACCELERATEABLE_H_
#define INCLUDE_IACCELERATEABLE_H_

class IAccelerateable {
 private:
 public:
    virtual void modifySpeedX(float spd) = 0;
    virtual void modifySpeedY(float spd) = 0;
};

#endif  // INCLUDE_IACCELERATEABLE_H_
