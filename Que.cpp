#include <iostream>
#define MAX 5  // Maximum size of the queue
using namespace std;

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to add an element (enqueue)
    void enqueue(int x) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        cout << "Inserted " << x << endl;
    }

    // Function to remove an element (dequeue)
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Removed " << arr[front] << endl;
        if (front == rear) {
            front = -1;  // Queue is empty now
            rear = -1;
        } else {
            front = (front + 1) % MAX;  // Circular increment of front
        }
    }

    // Function to display the queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(15);
    q1.enqueue(20);
    q1.enqueue(25);
    
    q1.display();   // Displays the queue elements

    q1.dequeue();   // Removes the first element
    q1.display();   // Displays the updated queue

    q1.enqueue(30); // Inserts a new element, demonstrating circular nature
    q1.display();   // Displays the updated queue

    return 0;
}

