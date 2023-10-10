#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <queue>
#include <unordered_map>

Point2D Cat::Move(World* world) {
    int temp = 0;
    auto pos = world->getCat();
    std::queue<Point2D> open;
    std::unordered_map<int, Point2D> closed;

    open.push(pos);
    closed.emplace(temp, pos);
    while (!open.empty()) {
        std::vector<Point2D> neighbors = neighbours(world);
        Point2D current = open.front();
        for(int x = 0; x < neighbors.size(); x++)
        {
            for(const auto& key: closed) {
                if (neighbors.at(x) != closed.at(key.first))
                {
                    open.push(neighbors.at(x));
                    temp++;
                    closed.emplace(temp, neighbors.at(x));
                }
            }
        }
        //int h = abs(current.x – goal.x) +
        //        abs(current.y – goal.y)
        //for(int x = 0; x < world->isValidPosition())
    };
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