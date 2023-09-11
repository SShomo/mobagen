#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2f AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to match the heading of neighbors = Average velocity
  Vector2f averageVelocity = Vector2f::zero();
  int neighSize = 0;
  // todo: add your code here to align each boid in a neighborhood
  // hint: iterate over the neighborhood
  if(neighborhood.size() > 1)
  {
    for(int x = 0; x < neighborhood.size(); x++)
    {
      auto temp = boid->getPosition() - neighborhood[x]->getPosition();
      auto tempsr= sqrt(temp.x + temp.y);

      if(tempsr > boid->getDetectionRadius())
      {
        averageVelocity += neighborhood[x]->getPosition();
        neighSize++;
      }
      averageVelocity + boid->getVelocity();
    }

    averageVelocity /= neighborhood.size() + 1;
  }



  return Vector2f::normalized(averageVelocity);
}