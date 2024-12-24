//#include<iostream>
//
//using namespace std;
//
//struct Edge {
//    int data;
//    Edge *next;
//};
//
//struct Vertex {
//    int data;
//    Edge *head;
//    Vertex *next;
//} *vertexList = NULL;
//
//void insert_vertex(int data) {
//    Vertex *newVertex = new Vertex;
//    newVertex->data = data;
//    newVertex->head = NULL;
//    newVertex->next = NULL;
//
//    if (vertexList == NULL) {
//        vertexList = newVertex;
//    } else {
//        Vertex *last = vertexList;
//        while (last->next != NULL) {
//            last = last->next;
//        }
//        last->next = newVertex;
//    }
//}
//
//bool check_vertex(int data) {
//    Vertex *temp = vertexList;
//    while (temp != NULL) {
//        if (temp->data == data) {
//            return true;
//        }
//        temp = temp->next;
//    }
//    cout << "Vertex Not Found: " << data << endl;
//    return false;
//}
//
//void add_edge(int from, int to) {
//    Vertex *temp = vertexList;
//    while (temp != NULL && temp->data != from) {
//        temp = temp->next;
//    }
//
//    if (temp == NULL) {
//        cout << "Source Vertex Not Found: " << from << endl;
//        return;
//    }
//
//    if (check_vertex(to)) {
//        Edge *newEdge = new Edge;
//        newEdge->data = to;
//        newEdge->next = NULL;
//
//        if (temp->head == NULL) {
//            temp->head = newEdge;
//        } else {
//            Edge *tail = temp->head;
//            while (tail->next != NULL) {
//                tail = tail->next;
//            }
//            tail->next = newEdge;
//        }
//    }
//}
//
//void delete_edge(int from, int to) {
//    Vertex *temp = vertexList;
//    while (temp != NULL && temp->data != from) {
//        temp = temp->next;
//    }
//
//    if (temp == NULL) {
//        cout << "Vertex Not Found: " << from << endl;
//        return;
//    }
//
//    Edge *prev = NULL, *cur = temp->head;
//    while (cur != NULL) {
//        if (cur->data == to) {
//            if (prev == NULL) {
//                temp->head = cur->next;
//            } else {
//                prev->next = cur->next;
//            }
//            delete cur;
//            cout << "Edge between " << from << " and " << to << " deleted." << endl;
//            return;
//        }
//        prev = cur;
//        cur = cur->next;
//    }
//
//    cout << "Edge Not Found: " << to << endl;
//}
//
//void display() {
//    Vertex *temp = vertexList;
//    while (temp != NULL) {
//        cout << temp->data << " -> ";
//        Edge *edgeTemp = temp->head;
//        while (edgeTemp != NULL) {
//            cout << edgeTemp->data << " ";
//            edgeTemp = edgeTemp->next;
//        }
//        cout << endl;
//        temp = temp->next;
//    }
//}
//
//int main() {
//    insert_vertex(1);
//    insert_vertex(2);
//    insert_vertex(3);
//    insert_vertex(4);
//    insert_vertex(5);
//
//    add_edge(1, 2);
//    add_edge(2, 3);
//    add_edge(1, 4);
//    add_edge(4, 5);
//    add_edge(3, 1);
//
//    cout << "Initial Adjacency List:" << endl;
//    display();
//
//    delete_edge(1, 2);
//    cout << "\nAdjacency List After Deleting Edge (1, 2):" << endl;
//    display();
//
//    delete_edge(2, 3);
//    cout << "\nAdjacency List After Deleting Edge (2, 3):" << endl;
//    display();
//
//    return 0;
//}

#include<iostream>

using namespace std;

struct Edge {
    int data;
    Edge *next;
};

struct Vertex {
    int data;
    Edge *head;
    Vertex *next;
} *vertexList = NULL;

// Function to insert a vertex
void insert_vertex(int data) {
    Vertex *newVertex = new Vertex;
    newVertex->data = data;
    newVertex->head = NULL;
    newVertex->next = NULL;

    if (vertexList == NULL) {
        vertexList = newVertex;
    } else {
        Vertex *last = vertexList;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newVertex;
    }
}

// Function to check if a vertex exists
bool check_vertex(int data) {
    Vertex *temp = vertexList;
    while (temp != NULL) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to add an edge between two vertices
void add_edge(int from, int to) {
    Vertex *temp = vertexList;
    while (temp != NULL && temp->data != from) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Source Vertex Not Found: " << from << endl;
        return;
    }

    if (check_vertex(to)) {
        Edge *newEdge = new Edge;
        newEdge->data = to;
        newEdge->next = NULL;

        if (temp->head == NULL) {
            temp->head = newEdge;
        } else {
            Edge *tail = temp->head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = newEdge;
        }
    }
}

// Function to delete an edge between two vertices
void delete_edge(int from, int to) {
    Vertex *temp = vertexList;
    while (temp != NULL && temp->data != from) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Vertex Not Found: " << from << endl;
        return;
    }

    Edge *prev = NULL, *cur = temp->head;
    while (cur != NULL) {
        if (cur->data == to) {
            if (prev == NULL) {
                temp->head = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            cout << "Edge between " << from << " and " << to << " deleted." << endl;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    cout << "Edge Not Found: " << to << endl;
}

// Function to display the adjacency list
void display() {
    Vertex *temp = vertexList;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        Edge *edgeTemp = temp->head;
        while (edgeTemp != NULL) {
            cout << edgeTemp->data << " ";
            edgeTemp = edgeTemp->next;
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    // Insert the vertices into the graph
    for (int i = 1; i <= numNodes; ++i) {
        insert_vertex(i);
    }

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    // Take input for edges
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cout << "Enter edge " << i + 1 << " (from vertex to vertex): ";
        cin >> from >> to;
        add_edge(from, to);
    }

    cout << "\nAdjacency List:" << endl;
    display();

    return 0;
}


