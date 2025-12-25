#include "Graph.h"

Graph::Graph(int vertices) {
    V = vertices;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back({ v, weight });
    adj[v].push_back({ u, weight });
}

// ---------------- BFS ----------------
void Graph::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto nbr : adj[node]) {
            if (!visited[nbr.first]) {
                visited[nbr.first] = true;
                q.push(nbr.first);
            }
        }
    }
    cout << endl;
}

// ---------------- DFS ----------------
void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    DFSUtil(start, visited);
    cout << endl;
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (auto nbr : adj[v]) {
        if (!visited[nbr.first]) {
            DFSUtil(nbr.first, visited);
        }
    }
}

// ---------------- Dijkstra ----------------
void Graph::dijkstra(int source) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({ 0, source });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto nbr : adj[u]) {
            int v = nbr.first;
            int w = nbr.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    cout << "Shortest Rescue Routes from Location " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To Location " << i << " = " << dist[i] << endl;
    }
}
