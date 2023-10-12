#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce;
  Vector2f centerMass=Vector2f::zero();
  float coRad = boid->getDetectionRadius();
  int count = 0;
  // todo: add your code here to make a force towards the center of mass
  // hint: iterate over the neighborhood
  if(neighborhood.size() > 1)
  {
    for(int x = 0; x < neighborhood.size(); x++)
    {
      auto temp = boid->getPosition() - neighborhood[x]->getPosition();
      auto tempsr= sqrt(pow(temp.x, 2.f) + pow(temp.y, 2.f));

      if(tempsr <= boid->getDetectionRadius())
      {
        centerMass += neighborhood[x]->getPosition();
        count++;
      }
    }
    if(count != 0)
      centerMass /= count;

    auto temp = centerMass - boid->getPosition();
    if(coRad != 0)
      cohesionForce = temp/ coRad;
  }
  else
    cohesionForce = Vector2f(0, 0);

  // find center of mass
  return cohesionForce;
}