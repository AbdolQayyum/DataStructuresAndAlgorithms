#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Class for Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Function to insert at the end
    void insertAtEnd(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            temp->prev = NULL;
            head = temp;
        } else {
            Node* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = temp;
            temp->prev = last;
        }
    }

    // Function to insert at a specific position
    void insertAtPosition(int value, int pos) {
        Node* temp = new Node;
        temp->data = value;

        if (pos == 1) {  // Insert at the start
            temp->next = head;
            temp->prev = NULL;
            if (head != NULL) head->prev = temp;
            head = temp;
            return;
        }

        Node* cur = head;
        for (int i = 1; i < pos - 1 && cur != NULL; i++) {
            cur = cur->next;
        }

        if (cur == NULL) {
            cout << "Position out of bounds." << endl;
            delete temp;
        } else {
            temp->next = cur->next;
            if (cur->next != NULL) cur->next->prev = temp;
            cur->next = temp;
            temp->prev = cur;
        }
    }

    // Function to delete the first node
    void deleteFromStart() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
    }

    // Function to delete the last node
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }

        if (last->prev != NULL) {
            last->prev->next = NULL;
        } else {
            head = NULL;
        }
        delete last;
    }

    // Function to delete from a specific position
    void deleteFromPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* cur = head;
        for (int i = 1; i < pos && cur != NULL; i++) {
            cur = cur->next;
        }

        if (cur == NULL) {
            cout << "Position out of bounds." << endl;
        } else {
            if (cur->prev != NULL) cur->prev->next = cur->next;
            if (cur->next != NULL) cur->next->prev = cur->prev;
            if (cur == head) head = cur->next;
            delete cur;
        }
    }

    // Display the list from start to end
    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the list from end to start
    void displayBackward() {
        Node* temp = head;
        if (temp == NULL) return;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// Main function to demonstrate all operations
int main() {
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.displayForward();     // Output: 10 20 30

    list.insertAtPosition(15, 2);
    list.displayForward();     // Output: 10 15 20 30

    list.deleteFromStart();
    list.displayForward();     // Output: 15 20 30

    list.deleteFromEnd();
    list.displayForward();     // Output: 15 20

    list.deleteFromPosition(2);
    list.displayForward();     // Output: 15

    list.displayBackward();    // Output: 15

    return 0;
}

