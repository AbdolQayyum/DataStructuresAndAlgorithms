#include <iostream>
#include <stack>
using namespace std;

#define MAX 100

// Node structure for adjacency list
struct Node {
    int vertex;
    Node* next;
};

// Vertex structure
struct Vertex {
    char label;
    bool visited;
    Node* head; // Head of adjacency list for the vertex
};

Vertex* vertices[MAX]; // Array to store vertices
int vertexCount = 0;   // Number of vertices
stack<int> stk;        // Stack for DFS traversal

// Function to add a vertex to the graph
void addVertex(char label) {
    Vertex* vertex = new Vertex;
    vertex->label = label;
    vertex->visited = false;
    vertex->head = nullptr;
    vertices[vertexCount++] = vertex;
}

// Function to add an edge to the adjacency list
void addEdge(int start, int end) {
    if (start >= vertexCount || end >= vertexCount) {
        cout << "Invalid edge: " << start << " -> " << end << endl;
        return;
    }

    // Add edge from start to end
    Node* newNode = new Node;
    newNode->vertex = end;
    newNode->next = vertices[start]->head;
    vertices[start]->head = newNode;

    // Add edge from end to start (for undirected graph)
    newNode = new Node;
    newNode->vertex = start;
    newNode->next = vertices[end]->head;
    vertices[end]->head = newNode;
}

// Function to display a vertex
void displayVertex(int vertexIndex) {
    cout << vertices[vertexIndex]->label << " ";
}

// Function to get the next unvisited adjacent vertex
int getAdjUnvisitedVertex(int vertexIndex) {
    Node* temp = vertices[vertexIndex]->head;

    while (temp != nullptr) {
        if (!vertices[temp->vertex]->visited) {
            return temp->vertex;
        }
        temp = temp->next;
    }
    return -1;
}

// Depth First Search using adjacency list
void depthFirstSearch(int start) {
    if (start >= vertexCount) {
        cout << "Invalid starting vertex!" << endl;
        return;
    }

    // Mark the starting vertex as visited and push it onto the stack
    vertices[start]->visited = true;
    displayVertex(start);
    stk.push(start);

    while (!stk.empty()) {
        int unvisitedVertex = getAdjUnvisitedVertex(stk.top());

        if (unvisitedVertex == -1) {
            stk.pop();
        } else {
            vertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            stk.push(unvisitedVertex);
        }
    }

    // Reset visited status for all vertices
    for (int i = 0; i < vertexCount; i++) {
        vertices[i]->visited = false;
    }
}

int main() {
    int numVertices, numEdges;

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
    cout << "Enter the starting vertex for DFS (index): ";
    cin >> startVertex;

    cout << "Depth First Search traversal: ";
    depthFirstSearch(startVertex);
    cout << endl;

    return 0;
}

