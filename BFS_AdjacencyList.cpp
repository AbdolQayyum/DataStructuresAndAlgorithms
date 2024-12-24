#include <iostream>
#include <queue>
#include <list>
using namespace std;

#define MAX 100

struct Vertex {
    char label;
    bool visited;
};

Vertex* lstVertices[MAX];  // Array to store vertices
list<int> adjList[MAX];    // Adjacency list for the graph
int vertexCount = 0;       // Number of vertices
queue<int> q;              // Queue for BFS traversal

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
    adjList[start].push_back(end);
    adjList[end].push_back(start);  // For undirected graph
}

// Function to display a vertex
void displayVertex(int vertexIndex) {
    cout << lstVertices[vertexIndex]->label << " ";
}

// Function to perform Breadth-First Search (BFS)
void breadthFirstSearch(int start) {
    if (start >= vertexCount) {
        cout << "Invalid starting vertex!" << endl;
        return;
    }

    // Mark the starting vertex as visited and enqueue it
    lstVertices[start]->visited = true;
    displayVertex(start);
    q.push(start);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        // Visit all unvisited adjacent vertices and enqueue them
        for (int neighbor : adjList[currentVertex]) {
            if (!lstVertices[neighbor]->visited) {
                lstVertices[neighbor]->visited = true;
                displayVertex(neighbor);
                q.push(neighbor);
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

    // Initialize adjacency list
    for (int i = 0; i < MAX; i++) {
        adjList[i].clear();
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

