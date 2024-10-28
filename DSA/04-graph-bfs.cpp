#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList; // Adjacency list represented as a vector of vectors

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void BFS(int start) {
        vector<bool> visited(numVertices, false);
        queue<int> queue;
        queue.push(start);
        visited[start] = true;
        while (!queue.empty()) {
            int vertex = queue.front();
            queue.pop();
            cout << vertex << " ";

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    queue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
    void printAdjList() {
        for (int i = 0; i < numVertices; ++i) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5); // Create a graph with 5 vertices (0 to 4)
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    cout << "Graph representation (Adjacency List):" << endl;
    graph.printAdjList();

    cout << "\nBFS starting from vertex 0: ";
    graph.BFS(0);

    return 0;
}