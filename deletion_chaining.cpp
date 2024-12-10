#include <iostream>
using namespace std;

#define SIZE 7


struct Node {
    int data;
    Node* next;
};


Node* chain[SIZE];


void init() {
    for (int i = 0; i < SIZE; i++) {
        chain[i] = NULL;
    }
}


void insert(int value) {
   
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    
    int key = value % SIZE;

    
    if (chain[key] == NULL) {
        chain[key] = newNode;
    } else {
        // Collision
        Node* temp = chain[key];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void remove(int value) {
    
    int key = value % SIZE;

    
    if (chain[key] == NULL) {
        cout << "Value " << value << " not found in the hash table.\n";
        return;
    }

    
    Node* temp = chain[key];
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == value) {
           
            if (prev == NULL) {
                
                chain[key] = temp->next;
            } else {
                
                prev->next = temp->next;
            }
            delete temp;
            cout << "Value " << value << " deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    
    cout << "Value " << value << " not found in the hash table.\n";
}


void print() {
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

int main() {
    
    init();

    
    insert(24);
    insert(52);
    insert(91);
    insert(67);
    insert(48);
    insert(83);

    // Print the hash table
    cout << "Hash Table before deletion:\n";
    print();

    // Delete some values
    remove(91);
    remove(48);
    remove(15); 

    
    cout << "\nHash Table after deletion:\n";
    print();

    return 0;
}

