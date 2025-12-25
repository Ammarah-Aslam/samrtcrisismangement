#include "RoutingManager.h"

int main() {

    RoutingManager routing(5);

    routing.createCityMap();

    cout << "\n--- City Traversal ---\n";
    routing.traverseCity(0);

    cout << "\n--- Shortest Rescue Route ---\n";
    routing.showRoutes(0);

    return 0;

}
