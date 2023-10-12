#ifndef CAT_H
#define CAT_H

#include "Agent.h"
#include "vector"

class Cat : public Agent {
public:
  explicit Cat() : Agent(){};
  Point2D Move(World*) override;
  std::vector<Point2D> neighbours(World*);
};

#endif  // CAT_H
