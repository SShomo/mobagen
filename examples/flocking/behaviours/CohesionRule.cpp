#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce;
  Vector2f centerMass=Vector2f::zero();
  float coRad = boid->getDetectionRadius();
  // todo: add your code here to make a force towards the center of mass
  // hint: iterate over the neighborhood
  if(neighborhood.size() > 1)
  {
    for(int x = 0; x < neighborhood.size(); x++)
    {
      centerMass += neighborhood[x]->getPosition();
    }
    centerMass /= neighborhood.size();
    auto temp = centerMass - boid->getPosition();
    cohesionForce = temp/ coRad;
  }
  else
    cohesionForce = Vector2f(0, 0);

  // find center of mass
  return cohesionForce;
}