#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to avoid boids too close
  Vector2f separatingForce = Vector2f::zero();
//sum then divide
      float desiredDistance = desiredMinimalDistance;
      Vector2f position = boid->transform.position;

      int countCloseFlockmates = 0;
  //    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
      if (!neighborhood.empty()) {
          for(int x = 0; x < neighborhood.size(); x++)
          {
            auto temp = boid->getPosition() - neighborhood[x]->getPosition();
            auto tempsr= sqrt(pow(temp.x, 2.f) + pow(temp.y, 2.f));

            if(0 < tempsr && tempsr <= boid->getDetectionRadius())
            {
              countCloseFlockmates++;
              separatingForce += Vector2f(1,1) / (((position - neighborhood[x]->getPosition()) / tempsr) / tempsr);
            }
          }
  //        // todo: find and apply force only on the closest mates
      }
      if(countCloseFlockmates != 0)
          separatingForce /= countCloseFlockmates;

  separatingForce = Vector2f::normalized(separatingForce);

  return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
  bool valusHasChanged = false;

  if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
    valusHasChanged = true;
  }

  return valusHasChanged;
}
