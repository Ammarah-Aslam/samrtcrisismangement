#ifndef ROUTINGMANAGER_H
#define ROUTINGMANAGER_H

#include "Graph.h"

class RoutingManager {
private:
    Graph cityGraph;

public:
    RoutingManager(int locations);

    void createCityMap();
    void showRoutes(int source);
    void traverseCity(int source);
};

#endif
#pragma once
