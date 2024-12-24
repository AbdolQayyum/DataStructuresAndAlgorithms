#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

struct Vertex {
    char label;
    bool visited;
};

Vertex* lstVertices[MAX]; // Array to store vertices
int adjMatrix[MAX][MAX];  // Adjacency matrix
int vertexCount = 0;      // Number of vertices
queue<int> q;             // Queue for BFS traversal

// Function to add a vertex to the graph
void addVertex(char label) {
    Vertex* vertex = new Vertex;
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

// Function to add an edge to the graph
void addEdge(int start, int end) {
    if (start >= vertexCount || end >= vertexCount) {
        cout << "Invalid edge: " << start << " -> " << end << endl;
        return;
    }
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1; // For undirected graph
}

// Function to display a vertex
void displayVertex(int vertexIndex) {
    cout << lstVertices[vertexIndex]->label << " ";
}

// Function to find the next unvisited adjacent vertex
int getAdjUnvisitedVertex(int vertexIndex) {
    for (int i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertexIndex][i] == 1 && !lstVertices[i]->visited) {
            return i;
        }
    }
    return -1;
}

// Breadth First Search using queue
void breadthFirstSearch(int start) {
    if (start >= vertexCount) {
        cout << "Invalid starting vertex!" << endl;
        return;
    }

    // Mark the starting vertex as visited and push it into the queue
    lstVertices[start]->visited = true;
    displayVertex(start);
    q.push(start);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        // Visit all unvisited adjacent vertices and enqueue them
        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !lstVertices[i]->visited) {
                lstVertices[i]->visited = true;
                displayVertex(i);
                q.push(i);
            }
        }
    }

    // Reset the visited status for all vertices after traversal
    for (int i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

int main() {
    int numVertices, numEdges;

    // Initialize adjacency matrix
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Input number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the labels of the vertices:" << endl;
    for (int i = 0; i < numVertices; i++) {
        char label;
        cout << "Vertex " << i << ": ";
        cin >> label;
        addVertex(label);
    }

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (start end):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        cin >> start >> end;
        addEdge(start, end);
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS (index): ";
    cin >> startVertex;

    cout << "Breadth First Search traversal: ";
    breadthFirstSearch(startVertex);
    cout << endl;

    return 0;
}

