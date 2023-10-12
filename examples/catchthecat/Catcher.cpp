#include "Catcher.h"
#include "World.h"

Point2D Catcher::Move(World* world) {
  auto side = world->getWorldSideSize() / 2;
  for (;;) {
    std::vector<Point2D> path = generatePath(world);
    //Point2D p = {Random::Range(-side, side), Random::Range(-side, side)};
    Point2D p = path.front();
    auto cat = world->getCat();
    if (cat.x != p.x && cat.y != p.y && !world->getContent(p)) return p;
  }
}
