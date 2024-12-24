#include <iostream>
#include <vector>
using namespace std;

void printAdjList(const vector<vector<int>>& adjList, int nodes) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < nodes; i++) {
        cout << (i+1) << ": ";  // Print node number (1-based indexing)
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
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

    // Create an adjacency list (array of vectors)
    vector<vector<int>> adjList(nodes);

    cout << "Enter edges (start_node end_node):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u-1].push_back(v); // Add v to the list of u (adjust for zero-indexing)
        adjList[v-1].push_back(u); // For undirected graph, add u to the list of v
    }

    // Print adjacency list
    printAdjList(adjList, nodes);

    return 0;
}

