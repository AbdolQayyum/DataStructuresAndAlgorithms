#include <iostream>
using namespace std;

class Stack {
private:
    int* stackArray;
    int top;
    int capacity;

public:
    // Constructor to initialize the stack
    Stack(int size) {
        capacity = size;
        stackArray = new int[capacity];
        top = -1;  // Stack is initially empty
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] stackArray;
    }

    // Push an element to the top of the stack
    void push(int element) {
        if (top == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << element << endl;
        } else {
            stackArray[++top] = element;
            cout << "Pushed " << element << " into the stack." << endl;
        }
    }

    // Pop an element from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return -1;
        } else {
            int poppedElement = stackArray[top--];
            cout << "Popped " << poppedElement << " from the stack." << endl;
            return poppedElement;
        }
    }

    // Peek at the top element of the stack
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return stackArray[top];
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Display the stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << stackArray[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack(5);  // Create a stack of size 5

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    stack.pop();
    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();  // Trying to pop from an empty stack
    return 0;
}

