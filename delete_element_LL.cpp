#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(NULL) {} 
};

// Function to delete all even-positioned nodes
void deleteEvenPositionedNodes(Node*& head) {
    if (!head || !head->next) {
       
        return;
    }

    Node* current = head;
    Node* prev = NULL;  
    int position = 1;   

    while (current != NULL) {
        if (position % 2 == 0) {
           
            if (prev != NULL) {
                prev->next = current->next; 
            }
            Node* temp = current;           
            current = current->next;       
            delete temp;                  
        } else {
            
            prev = current;
            current = current->next;
        }
        position++;
    }
}

// Helper function to add a node at the end of the list
void append(Node*& head, int new_data) {
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
}


void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    
    // Creating the linked list
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    append(head, 6);

    cout << "Original List: ";
    printList(head);

    // Deleting even-positioned nodes
    deleteEvenPositionedNodes(head);

    cout << "After Deleting Even-Positioned Nodes: ";
    printList(head);

    return 0;
}

