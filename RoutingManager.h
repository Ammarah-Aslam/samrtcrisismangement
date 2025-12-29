#ifndef ROUTINGMANAGER_H
#define ROUTINGMANAGER_H

#include "Graph.h"
#include <string>

class RoutingManager {
private:
  Graph cityGraph;

public:
  RoutingManager(int locations);

  void createCityMap();
  std::string showRoutes(int source);
  std::string doBFS(int source);
  std::string doDFS(int source);
};

#endif
