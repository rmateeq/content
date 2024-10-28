#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Graph class using Adjacency List representation
class GraphList {
private:
    int numVertices;
    vector<list<int>> adjList;

public:
    GraphList(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
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

// Graph class using Adjacency Matrix representation
class GraphMatrix {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }

    void printAdjMatrix() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;

    // Adjacency List representation
    GraphList graphList(vertices);
    graphList.addEdge(0, 1);
    graphList.addEdge(0, 2);
    graphList.addEdge(1, 3);
    graphList.addEdge(2, 4);
    cout << "Graph representation using Adjacency List:" << endl;
    graphList.printAdjList();

    cout << endl;

    // Adjacency Matrix representation
    GraphMatrix graphMatrix(vertices);
    graphMatrix.addEdge(0, 1);
    graphMatrix.addEdge(0, 2);
    graphMatrix.addEdge(1, 3);
    graphMatrix.addEdge(2, 4);
    cout << "Graph representation using Adjacency Matrix:" << endl;
    graphMatrix.printAdjMatrix();

    return 0;
}