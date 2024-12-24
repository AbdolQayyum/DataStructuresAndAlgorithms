#include <iostream>
using namespace std;

void printAdjMatrix(int** matrix, int nodes) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;

    // Dynamically allocate a 2D array
    int** adjMatrix = new int*[nodes];
    for (int i = 0; i < nodes; i++) {
        adjMatrix[i] = new int[nodes]();
    }

    cout << "Enter edges (start_node end_node):" << endl;
    for (int i = 0; i <= edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1; // For undirected graph, also add adjMatrix[v][u] = 1;
        adjMatrix[v][u] = 1; // Uncomment for undirected graph
    }

    // Print adjacency matrix
    printAdjMatrix(adjMatrix, nodes);

    // Free allocated memory
    for (int i = 0; i < nodes; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}


