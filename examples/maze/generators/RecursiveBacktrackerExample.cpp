#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>

bool RecursiveBacktrackerExample::Step(World* w) {
  Color32 _red = Color32(255, 0, 0, 255);
  Color32 _black = Color32(0, 0, 0, 255);
  Point2D currentPos = Point2D(-10,-10);
  std::vector<Point2D> numNeigh;


  w->SetNodeColor(currentPos, _red);
  stack.push_back(currentPos);
  while(!stack.empty())
  {
    //if(w->GetNodeColor(currentPos) == _red){ w->SetNodeColor(currentPos, _black); }
    //else { w->SetNodeColor(currentPos, _red); }
    numNeigh = getVisitables(w, currentPos);
    if(!numNeigh.empty()) { // setting North, south, west, and east false to remove wall
      if (numNeigh.size() == 1) {
        if (numNeigh[0].x > currentPos.x ) {
          currentPos.y -= 1;
          stack.push_back(currentPos);
        } else if (numNeigh[0] == 'd') {
          currentPos.y += 1;
          stack.push_back(currentPos);
        } else if (numNeigh[0] == 'l') {
          currentPos.x -= 1;
          stack.push_back(currentPos);
        } else if (numNeigh[0] == 'r') {
          currentPos.x += 1;
          stack.push_back(currentPos);
        }
      } else {
        int randomNum = rand() % numNeigh.size();
        if (numNeigh[randomNum] == 'u') {
          currentPos.y -= 1;
          stack.push_back(currentPos);
        } else if (numNeigh[randomNum] == 'd') {
          currentPos.y += 1;
          stack.push_back(currentPos);
        } else if (numNeigh[randomNum] == 'l') {
          currentPos.x -= 1;
          stack.push_back(currentPos);
        } else if (numNeigh[randomNum] == 'r') {
          currentPos.x += 1;
          stack.push_back(currentPos);
        }
      }
    }else{ stack.erase(stack.begin()); }
  }
  return true;
}

void RecursiveBacktrackerExample::Clear(World* world) {
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}
Point2D RecursiveBacktrackerExample::randomStartPoint(World* world) {
  auto sideOver2 = world->GetSize() / 2;

  // todo: change this if you want
  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[x][y]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;

  if(p.y > 0 && visited[p.x][p.y - 1])
    visitables.push_back(Point2D(p.x, p.y - 1));

  if(p.x + 1 < sideOver2 && visited[p.x + 1][p.y])
    visitables.push_back(Point2D(p.x + 1, p.y));

  if(p.y + 1 < sideOver2 && visited[p.x][p.y + 1])
    visitables.push_back(Point2D(p.x, p.y + 1));

  if(p.x > 0 && visited[p.x - 1][p.y])
    visitables.push_back(Point2D(p.x - 1, p.y));
  return visitables;
}
