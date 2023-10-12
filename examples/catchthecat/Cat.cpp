#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <queue>
#include <unordered_map>

Point2D Cat::Move(World* world) {
  //auto rand = Random::Range(0, 5);
  std::vector<Point2D> path = generatePath(world);
  auto pos = world->getCat();
  return path.back();
/*  switch (rand) {
    case 0:
      return World::NE(pos);
    case 1:
      return World::NW(pos);
    case 2:
      return World::E(pos);
    case 3:
      return World::W(pos);
    case 4:
      return World::SW(pos);
    case 5:
      return World::SE(pos);
    default:
      throw "random out of range";
  }*/
}
    /*  while(true)
     {
         auto rand = Random::Range(0, 5);
         switch (rand) {
             case 0:
                 if(world->catCanMoveToPosition(World::NE(pos)))
                   return World::NE(pos);
             case 1:
                 if(world->catCanMoveToPosition(World::NW(pos)))
                   return World::NW(pos);
             case 2:
                 if(world->catCanMoveToPosition(World::E(pos)))
                   return World::E(pos);
             case 3:
                 if(world->catCanMoveToPosition(World::W(pos)))
                   return World::W(pos);
             case 4:
                 if(world->catCanMoveToPosition(World::SW(pos)))
                    return World::SW(pos);
             case 5:
                 if(world->catCanMoveToPosition(World::SE(pos)))
                   return World::SE(pos);
             default:
                 throw "random out of range";
         }
  }*/

std::vector<Point2D> Cat::neighbours(World* world){
    std::vector<Point2D> neigh;
    auto pos = world->getCat();

    if(world->catCanMoveToPosition(World::NE(pos)))
        neigh.push_back(World::NE(pos));
    if(world->catCanMoveToPosition(World::NW(pos)))
        neigh.push_back(World::NW(pos));
    if(world->catCanMoveToPosition(World::E(pos)))
        neigh.push_back(World::E(pos));
    if(world->catCanMoveToPosition(World::W(pos)))
        neigh.push_back(World::W(pos));
    if(world->catCanMoveToPosition(World::SW(pos)))
        neigh.push_back(World::SW(pos));
    if(world->catCanMoveToPosition(World::SE(pos)))
        neigh.push_back(World::SE(pos));
    return neigh;
};