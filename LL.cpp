#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
};

// Class for Linked List
class LinkedList {
private:
    Node* head;     // Pointer to the head of the list

public:
    // Constructor
    LinkedList() {
        head = NULL; // Initially, the list is empty
    }

    // Function to insert a node at the end
    void insertAtEnd(int value) {
        Node* temp = new Node;   // Create a new node
        temp->data = value;
        temp->next = NULL;       // New node points to NULL

        if (head == NULL) {
            // If list is empty, head points to the new node
            head = temp;
        } else {
            // Traverse to the last node
            Node* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = temp;   // Last node now points to the new node
        }
    }

    // Function to insert a node at the start
    void insertAtStart(int value) {
        Node* temp = new Node;   // Create a new node
        temp->data = value;
        temp->next = head;       // New node points to the current head
        head = temp;             // Head now points to the new node
    }

    // Function to display the list
    void display() {
        Node* temp = head;       // Start from the head
        while (temp != NULL) {
            cout << temp->data << " ";  // Print node data
            temp = temp->next;          // Move to the next node
        }
        cout << endl;
    }

    // Function to delete a node from the start
    void deleteFromStart() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;       // Store the current head
        head = head->next;       // Move the head to the next node
        delete temp;             // Delete the old head
    }

    // Function to delete a node from the end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;         // If there's only one node, delete it
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next == NULL) {
                temp = temp->next;  // Find the second last node
            }
            delete temp->next;      // Delete the last node
            temp->next = NULL;      // Set the new last node's next to NULL
        }
    }
};

// Main function to demonstrate linked list operations
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();  // Output: 10 20 30

    list.insertAtStart(5);
    list.display();  // Output: 5 10 20 30

    list.deleteFromStart();
    list.display();  // Output: 10 20 30

    list.deleteFromEnd();
    list.display();  // Output: 10 20

    return 0;
}

