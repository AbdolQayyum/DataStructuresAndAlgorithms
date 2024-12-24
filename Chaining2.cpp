#include <iostream>
using namespace std;

// Define the size of the hash table
#define SIZE 7

// Define a linked list node
struct Node {
    int data;
    Node* next;
};

// Create an array of pointers (chains) to linked lists
Node* chain[SIZE];

// Initialize the hash table with NULL values
void init() {
    for (int i = 0; i < SIZE; i++) {
        chain[i] = NULL;
    }
}

// Function to insert a value into the hash table
void insert(int value) {
    int key = value % SIZE; // Hash function
    Node* newNode = new Node(); // Create a new node
    newNode->data = value;
    newNode->next = NULL;

    // If the chain is empty, directly insert
    if (chain[key] == NULL) {
        chain[key] = newNode;
    } else {
        // Collision occurred, insert at the end of the chain
        Node* temp = chain[key];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a value from the hash table
void deleteValue(int value) {
    int key = value % SIZE; // Hash function to find the index
    Node* temp = chain[key];
    Node* prev = NULL;

    // Traverse the chain to find the node to delete
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value is not found
    if (temp == NULL) {
        cout << "Value " << value << " not found in the hash table.\n";
        return;
    }

    // If the node to be deleted is the first node
    if (prev == NULL) {
        chain[key] = temp->next;
    } else {
        // Node is somewhere in the chain
        prev->next = temp->next;
    }

    delete temp; // Free the memory
    cout << "Value " << value << " deleted from the hash table.\n";
}

// Function to display the hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Chain[" << i << "] --> ";
        Node* temp = chain[i];
        while (temp != NULL) {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

// Main function
int main() {
    // Initialize the hash table
    init();

    // Insert values
    int values[] = {25, 37, 18, 55, 68, 49, 21, 10};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        insert(values[i]);
    }

    // Display the hash table before deletion
    cout << "Hash Table (Before Deletion):\n";
    display();

    // Delete values
    deleteValue(25); // Delete value 25
    deleteValue(55); // Delete value 55
    deleteValue(100); // Attempt to delete a value not in the hash table

    // Display the hash table after deletion
    cout << "\nHash Table (After Deletion):\n";
    display();

    return 0;
}

