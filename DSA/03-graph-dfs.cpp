#include <iostream>
#include <vector>
#include <stack>
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
    void DFS(int start) {
        vector<bool> visited(numVertices, false);
        stack<int> stack;
        stack.push(start);

        while (!stack.empty()) {
            int vertex = stack.top();
            stack.pop();

            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = true;
            }
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
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

    cout << "\nDFS starting from vertex 0: ";
    graph.DFS(0);

    return 0;
}