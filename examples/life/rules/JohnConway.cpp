#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {
  int size = world.SideSize();

  for(int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      Point2D p = Point2D(x, y);
      bool isAlive = world.Get(p);
      int neighbors = CountNeighbors(world, p);
      if(isAlive)
      {
        if(neighbors < 2)
          world.SetNext(p, false);
        if(neighbors == 2 || neighbors == 3)
          world.SetNext(p, true);
        if(neighbors > 3)
          world.SetNext(p, false);
      }
      else
      {
        if(neighbors == 3)
          world.SetNext(p, true);
      }
    }
  }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
  int neighbors = 0;
  if(world.Get(point.Up()))
    neighbors++;
  if(world.Get(point.Down()))
    neighbors++;
  if(world.Get(point.Left()))
    neighbors++;
  if(world.Get(point.Right()))
    neighbors++;
  if(world.Get(point.Left() + point.Up()))
    neighbors++;
  if(world.Get(point.Right() + point.Up()))
    neighbors++;
  if(world.Get(point.Left() + point.Down()))
    neighbors++;
  if(world.Get(point.Right() + point.Down()))
    neighbors++;

  return neighbors;
}
