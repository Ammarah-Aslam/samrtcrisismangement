#include "RoutingManager.h"

RoutingManager::RoutingManager(int locations)
    : cityGraph(locations)
{
    // constructor body intentionally left empty
}

void RoutingManager::createCityMap()
{
    cityGraph.addEdge(0, 1, 4);
    cityGraph.addEdge(0, 2, 2);

    cityGraph.addEdge(1, 2, 1);
    cityGraph.addEdge(1, 3, 5);

    cityGraph.addEdge(2, 3, 8);

    cityGraph.addEdge(3, 4, 3);
}

void RoutingManager::showRoutes(int source)
{
    cityGraph.dijkstra(source);
}

void RoutingManager::traverseCity(int source)
{
    cityGraph.BFS(source);
    cityGraph.DFS(source);
}

