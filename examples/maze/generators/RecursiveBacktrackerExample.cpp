#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>

bool RecursiveBacktrackerExample::Step(World* w) {
  Color32 _red = Color32(255, 0, 0, 255);
  Color32 _black = Color32(0, 0, 0, 255);
  Point2D currentPos;
  std::vector<Point2D> numNeigh;

  if(stack.empty())
  {
    currentPos = randomStartPoint(w);
    stack.push_back(currentPos);
  }else{
    currentPos.x = stack.back().x;
    currentPos.y = stack.back().y;
  }
  if(w->GetNodeColor(currentPos) != _black)
    w->SetNodeColor(currentPos, _red);
  visited[currentPos.x][currentPos.y] = true;
  numNeigh = getVisitables(w, currentPos);

  if(!numNeigh.empty()) { // setting North, south, west, and east false to remove wall
    if (numNeigh.size() == 1) {
      if (numNeigh[0].y == currentPos.y - 1) {
        w->SetNorth(currentPos, false);
      } else if (numNeigh[0].y == currentPos.y + 1) {
        w->SetSouth(currentPos, false);
      } else if (numNeigh[0].x == currentPos.x - 1) {
        w->SetWest(currentPos, false);
      } else if (numNeigh[0].x == currentPos.x + 1) {
        w->SetEast(currentPos, false);
      }
      stack.push_back(numNeigh[0]);
    } else if(numNeigh.size() > 1){
      int randomNum = rand() % numNeigh.size();
      if (numNeigh[randomNum].y == currentPos.y - 1) {
        w->SetNorth(currentPos, false);
      } else if (numNeigh[randomNum].y == currentPos.y + 1) {
        w->SetSouth(currentPos, false);
      } else if (numNeigh[randomNum].x == currentPos.x - 1) {
        w->SetWest(currentPos, false);
      } else if (numNeigh[randomNum].x == currentPos.x + 1) {
        w->SetEast(currentPos, false);
      }
      stack.push_back(numNeigh[randomNum]);
    }
    }else{
      if(w->GetNodeColor(currentPos) == _red && visited[currentPos.x][currentPos.y]){ w->SetNodeColor(currentPos, _black); }
      stack.pop_back();
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

  if(p.y > -10 && !visited[p.x][p.y - 1]) // check north
    visitables.push_back(Point2D(p.x, p.y - 1));

  if(p.x + 1 <= sideOver2 && !visited[p.x + 1][p.y]) //check east
    visitables.push_back(Point2D(p.x + 1, p.y));

  if(p.y + 1 <= sideOver2 && !visited[p.x][p.y + 1])// check south
    visitables.push_back(Point2D(p.x, p.y + 1));

  if(p.x > -10 && !visited[p.x - 1][p.y]) //check west
    visitables.push_back(Point2D(p.x - 1, p.y));

  return visitables;
}
