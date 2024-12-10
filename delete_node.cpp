#include <iostream>

using namespace std;

// Node structure for a doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

// Class to represent a doubly linked list
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    
    void append(int new_data) {
        Node* new_node = new Node(new_data);
        if (!head) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    }

    // Function to delete the first node
    void deleteFirstNode() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = NULL; 
        }
        delete temp; 
    }

    // Function to delete the last node
    void deleteLastNode() {
        if (!head) return;

        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        if (last->prev) {
            last->prev->next = NULL; 
        } else {
            head = NULL; 
        }
        delete last;
    }

    // Function to delete a node given by its key
    void deleteNodeByKey(int key) {
        Node* current = head;

        // Search for the key
        while (current != NULL) {
            if (current->data == key) {
                
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next; 
                }

                if (current->next) {
                    current->next->prev = current->prev;
                }

                delete current; 
                return; 
            }
            current = current->next;
        }
    }

    // Function to print the list
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Inserting nodes into the doubly linked list
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    cout << "Original List: ";
    list.printList();

    // Deleting the first node
    list.deleteFirstNode();
    cout << "After Deleting First Node: ";
    list.printList();

    // Deleting the last node
    list.deleteLastNode();
    cout << "After Deleting Last Node: ";
    list.printList();

    // Deleting a node by key
    int keyToDelete = 30; 
    list.deleteNodeByKey(keyToDelete);
    cout << "After Deleting Node with Key " << keyToDelete << ": ";
    list.printList();

    return 0;
}

