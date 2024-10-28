#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

// Define the adjacency list using a vector of vector of pairs
typedef pair<int, int> pii; // First element is the destination node, second is the weight
vector<vector<pii>> adjList;

vector<int> dijkstra(int start, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap to get the node with the smallest distance
    vector<int> dist(n, numeric_limits<int>::max()); // Distance values

    // Start from the source node
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Visit each adjacent vertex v
        for (auto & p : adjList[u]) {
            int v = p.first;
            int weight = p.second;

            // Calculate the new distance
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    int n, m; // n is the number of vertices, m is the number of edges
    cin >> n >> m;
    adjList.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Read edge and weight
        adjList[u].push_back(make_pair(v, w));
        // For undirected graph, add the reverse edge
        // adjList[v].push_back(make_pair(u, w)); // Uncomment this line for undirected graph
    }

    int start = 0; // Assuming starting node as node 0
    vector<int> distances = dijkstra(start, n);

    // Printing the shortest distances from the start
    cout << "Shortest distances from node " << start << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
