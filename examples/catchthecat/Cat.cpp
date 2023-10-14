#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <queue>
#include <unordered_map>

Point2D Cat::Move(World* world) {
    std::vector<Point2D> path = generatePath(world);
    //auto pos = world->getCat();
    if(path.size() != 0 && world->isValidPosition(path.back()))
        return path.back();
    else
        return Point2D(INT_MAX, INT_MAX);
}