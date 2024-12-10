#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }

    bool is_empty() {
        return front == NULL;
    }

    void insert_at_beg(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->prev = NULL;
        temp->next = front;
        if (is_empty()) {
            front = rear = temp;
        } else {
            front->prev = temp;
            front = temp;
        }
        cout << "Inserted " << x << " at beginning" << endl;
    }

    void insert_at_end(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        temp->prev = rear;
        if (is_empty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Inserted " << x << " at end" << endl;
    }

    void delete_fr_front() {
        if (is_empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        } else {
            front->prev = NULL;
        }
        cout << "Deleted " << temp->data << " from front" << endl;
        delete temp;
    }

    void delete_fr_rear() {
        if (is_empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear == NULL) {
            front = NULL;
        } else {
            rear->next = NULL;
        }
        cout << "Deleted " << temp->data << " from rear" << endl;
        delete temp;
    }

    void display() {
        if (is_empty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque d;
    d.insert_at_beg(10);
    d.insert_at_end(20);
    d.insert_at_beg(5);

    d.display();

    d.delete_fr_front();
    d.delete_fr_rear();

    d.display();

    return 0;
}

