#include <iostream>
#include <vector>
#include <list>
#include <limits>
using namespace std;

// Graph class using Adjacency List representation
class GraphList {
private:
    int numVertices;
    bool isDirected;
    bool isWeighted;
    vector<list<pair<int, int>>> adjList; // Pair of (neighbor, weight)

public:
    GraphList(int vertices, bool directed, bool weighted) {
        numVertices = vertices;
        isDirected = directed;
        isWeighted = weighted;
        adjList.resize(vertices);
    }

    void addEdge(int u, int v, int weight = 1) {
        adjList[u].emplace_back(v, weight);
        if (!isDirected) {
            adjList[v].emplace_back(u, weight);
        }
    }

    void printAdjList() {
        for (int i = 0; i < numVertices; ++i) {
            cout << i << ": ";
            for (auto neighbor : adjList[i]) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

// Graph class using Adjacency Matrix representation
class GraphMatrix {
private:
    int numVertices;
    bool isDirected;
    bool isWeighted;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int vertices, bool directed, bool weighted) {
        numVertices = vertices;
        isDirected = directed;
        isWeighted = weighted;
        adjMatrix.resize(vertices, vector<int>(vertices, numeric_limits<int>::max())); // Initialize with "infinity" for weighted graphs
    }

    void addEdge(int u, int v, int weight = 1) {
        adjMatrix[u][v] = weight;
        if (!isDirected) {
            adjMatrix[v][u] = weight;
        }
    }

    void printAdjMatrix() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] == numeric_limits<int>::max()) {
                    cout << "∞ ";
                } else {
                    cout << adjMatrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices;
    char directedChar, weightedChar;
    bool directed, weighted;

    // Input for graph preferences
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Is the graph directed (y/n)? ";
    cin >> directedChar;
    directed = (directedChar == 'y' || directedChar == 'Y');
    cout << "Is the graph weighted (y/n)? ";
    cin >> weightedChar;
    weighted = (weightedChar == 'y' || weightedChar == 'Y');

    // Create graphs
    GraphList graphList(vertices, directed, weighted);
    GraphMatrix graphMatrix(vertices, directed, weighted);

    // Input for edges
    int u, v, weight;
    char addMore;
    do {
        cout << "Enter edge (u v";
        if (weighted) cout << " weight";
        cout << "): ";
        cin >> u >> v;
        if (weighted) {
            cin >> weight;
        } else {
            weight = 1; // Default weight for unweighted graphs
        }
        graphList.addEdge(u, v, weight);
        graphMatrix.addEdge(u, v, weight);

        cout << "Add more edges (y/n)? ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    // Print graph representations
    cout << "\nGraph representation using Adjacency List:" << endl;
    graphList.printAdjList();

    cout << "\nGraph representation using Adjacency Matrix:" << endl;
    graphMatrix.printAdjMatrix();

    return 0;
}
