#include <iostream>
using namespace std;

struct Edge {
    int data;
    Edge* next;
};

struct Node {
    int data;
    Edge* head;
    Edge* tail;
    Node* next;
} *head = NULL, *tail = NULL;

// Insert a vertex
void insert_vertex(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->head = temp->tail = NULL;

    if (head == NULL) {
        temp->next = NULL;
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
        tail->next = NULL;
    }
}

// Check if vertex exists
bool check_vertex(int data) {
    Node* temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    return temp != NULL;
}

// Add an edge
void add_edge(int vname, int uname) {
    if (!check_vertex(vname) || !check_vertex(uname)) {
        cout << "Vertex not found!\n";
        return;
    }

    Node* temp = head;
    while (temp->data != vname) {
        temp = temp->next;
    }

    Edge* new_edge = new Edge;
    new_edge->data = uname;
    new_edge->next = NULL;

    if (temp->head == NULL) {
        temp->head = temp->tail = new_edge;
    } else {
        temp->tail->next = new_edge;
        temp->tail = new_edge;
    }
}

// Display the adjacency list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        Edge* etemp = temp->head;
        while (etemp != NULL) {
            cout << etemp->data << " ";
            etemp = etemp->next;
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    insert_vertex(1);
    insert_vertex(2);
    insert_vertex(3);
    insert_vertex(4);
    insert_vertex(5);

    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    add_edge(2, 5);
    add_edge(3, 1);
    add_edge(4, 5);

    display();

    return 0;
}

