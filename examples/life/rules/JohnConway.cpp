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
        if(neighbors == 3)
          world.SetNext(p, true);
    }
  }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
  int neighbors = 0;
  int size = world.SideSize();
  int north = (size + point.y - 1) % size;
  int south = (size + point.y + 1) % size;
  int east = (size + point.x + 1) % size;
  int west = (size + point.x - 1) % size;

  if(world.Get(point.Up()))
    neighbors++;
  if(world.Get(point.Left()))
    neighbors++;
  if(world.Get(point.Right()))
    neighbors++;
  if(world.Get(point.Down()))
    neighbors++;
  if(world.Get(Point2D(east, north)))
    neighbors++;
  if(world.Get(Point2D(west, north)))
    neighbors++;
  if(world.Get(Point2D(east, south)))
    neighbors++;
  if(world.Get(Point2D(west, south)))
    neighbors++;

  return neighbors;
}
