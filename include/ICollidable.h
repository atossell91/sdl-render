//  Copyright 2022 Anthony Tossell
#ifndef INCLUDE_ICOLLIDABLE_H_
#define INCLUDE_ICOLLIDABLE_H_

#include <memory>

class ICollidable {
 private:
 public:
    virtual bool isCollision(std::shared_ptr<ICollidable> const c) const = 0;
};

#endif  // INCLUDE_ICOLLIDABLE_H_
