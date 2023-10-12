#include "Agent.h"
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include "World.h"
using namespace std;
std::vector<Point2D> Agent::generatePath(World* w){
  unordered_map<Point2D, Point2D> cameFrom; // to build the flowfield and build the path
  queue<Point2D> frontier; // to store next ones to visit
  unordered_set<Point2D> frontierSet; // OPTIMIZATION to check faster if a point is in the queue
  unordered_map<Point2D, bool> visited; // use .at() to get data, if the element dont exist [] will give you wrong results
  vector<Point2D> path;

  Point2D temp;

  // bootstrap state
  auto catPos = w->getCat();
  frontier.push(catPos);
  frontierSet.insert(catPos);
  Point2D borderExit = {INT_MAX, INT_MAX}; // if at the end of the loop we dont find a border, we have to return random points

  while (!frontier.empty()){
    // get the current from frontier
    Point2D current = frontier.back();
    frontier.pop();
    // remove the current from frontierset
    frontierSet.erase(current);
    // mark current as visited
    visited[current] = true;
    // getVisitableNeighbors(world, current) returns a vector of neighbors that are not visited, not cat, not block, not in the queue
    vector<Point2D> neigh = getVisitableNeighbors(w, current);
    // iterate over the neighs:
    for(auto var : neigh)
    {
      if(frontierSet.find(var) != frontierSet.end())
      {
        cameFrom[var]= current; // for every neighbor set the cameFrom
                                // enqueue the neighbors to frontier and frontierset
        frontier.emplace(var);
        frontierSet.emplace(var);

        visited[var] = true;
        // do this up to find a visitable border and break the loop

        current = var;
        temp = var;
      }

      if(w->catWinsOnSpace(var))
        break;
    }
  }
  // if the border is not infinity, build the path from border to the cat using the camefrom map
  if(borderExit != Point2D(INT_MAX, INT_MAX))
  {
    path.emplace_back(cameFrom[temp]);
  }
  if(cameFrom.empty())  // if there isnt a reachable border, just return empty vector
  {
    return path;
  }
  return path;
  // if your vector is filled from the border to the cat, the first element is the catcher move, and the last element is the cat move
}


std::vector<Point2D> Agent::getVisitableNeighbors(World* w, Point2D current)
{
  std::vector<Point2D> newPos;

  if(w->isValidPosition(World::NE(current)))
    newPos.emplace_back(World::NE(current));
  if(w->isValidPosition(World::NW(current)))
    newPos.emplace_back(World::NW(current));
  if(w->isValidPosition(World::E(current)))
    newPos.emplace_back(World::E(current));

  if(w->isValidPosition(World::SE(current)))
    newPos.emplace_back(World::SE(current));
  if(w->isValidPosition(World::SW(current)))
    newPos.emplace_back(World::SW(current));
  if(w->isValidPosition(World::W(current)))
    newPos.emplace_back(World::W(current));

  return newPos;
}
