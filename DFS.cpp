#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 5

struct Vertex {
    char label;
    bool visited;
};

int stack[MAX];
int top = -1;

Vertex* lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;

// Stack functions
void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

bool isStackEmpty() {
    return top == -1;
}

// Graph functions
void addVertex(char label) {
    Vertex* vertex = new Vertex;
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
    cout << lstVertices[vertexIndex]->label << " ";
}

int getAdjUnvisitedVertex(int vertexIndex) {
    for (int i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertexIndex][i] == 1 && !lstVertices[i]->visited) {
            return i;
        }
    }
    return -1;
}

void depthFirstSearch() {
    lstVertices[0]->visited = true;
    displayVertex(0);
    push(0);

    while (!isStackEmpty()) {
        int unvisitedVertex = getAdjUnvisitedVertex(stack[top]);

        if (unvisitedVertex == -1) {
            pop();
        } else {
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }

    for (int i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

int main() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 4);

    cout << "Depth First Search: ";
    depthFirstSearch();

    return 0;
}

