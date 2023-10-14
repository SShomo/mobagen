#include "Catcher.h"
#include "World.h"

Point2D Catcher::Move(World* world) {
  auto side = world->getWorldSideSize() / 2;
  std::vector<Point2D> path = generatePath(world);
  int temp = 1;
  Point2D p = path.front();
    for (;;) {
    auto cat = world->getCat();
    if (cat != p)
        return p;
    else
    {
        p = path[temp];
        temp += 1;
    }
  }
}