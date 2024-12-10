#include <iostream>
#include <queue>
using namespace std;

#define V 5

// Initialize the adjacency matrix
void init(int arr[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

// Add edges
void addEdge(int arr[][V], int i, int j) {
    arr[i][j] = 1;
    arr[j][i] = 1;
}

// Print the adjacency matrix
void printAdjMatrix(int arr[][V]) {
    cout << "Adjacency Matrix:" << endl;
    cout << "  A B C D E" << endl;
    for (int i = 0; i < V; i++) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < V; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// BFS function
void bfs(int adjMatrix[][V], int start) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;  
    q.push(start);

    cout << "Breadth-First Search starting from vertex " << char('A' + start) << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << char('A' + current) << " ";

        // Visit all the adjacent vertices
        for (int i = 0; i < V; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int adjMatrix[V][V];
    init(adjMatrix);

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2); 
    addEdge(adjMatrix, 1, 3); 
    addEdge(adjMatrix, 2, 4); 
    addEdge(adjMatrix, 3, 4); 

    printAdjMatrix(adjMatrix);

    bfs(adjMatrix, 0);

    return 0;
}

