#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices);

    void addEdge(int u, int v, int weight);

    void BFS(int start);
    void DFS(int start);
    void DFSUtil(int v, vector<bool>& visited);

    void dijkstra(int source);
};

#endif
#pragma once
