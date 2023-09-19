#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2f AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to match the heading of neighbors = Average velocity
  Vector2f averageVelocity = Vector2f::zero();
  float neighSize = 0.0f;
  // todo: add your code here to align each boid in a neighborhood
  // hint: iterate over the neighborhood
  if(neighborhood.size() > 1)
  {
    for(int x = 0; x < neighborhood.size(); x++)
    {
      auto temp = boid->getPosition() - neighborhood[x]->getPosition();
      auto tempsr= sqrt(pow(temp.x, 2.f) + pow(temp.y, 2.f));

      if(tempsr <= boid->getDetectionRadius())
      {
        averageVelocity += neighborhood[x]->getVelocity();
        neighSize++;
      }
    }
    averageVelocity += boid->getVelocity();
    averageVelocity /= neighSize + 1.0f;
    auto temp = boid->getVelocity() - averageVelocity;
    auto tempsr= sqrt(pow(temp.x, 2.f) + pow(temp.y, 2.f));
    if(tempsr != 0)
    {
      averageVelocity = (averageVelocity / tempsr) *tempsr;
    }
  }

    return Vector2f::normalized(averageVelocity);
}