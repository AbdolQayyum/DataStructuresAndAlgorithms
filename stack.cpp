#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class CustomStack {
private:
    stack<int> s; 

public:
    
    void push(int value) {
        s.push(value);
    }

   
    void pop() {
        if (s.empty()) {
            throw runtime_error("Stack is empty. Cannot pop.");
        }
        s.pop();
    }


    int top() {
        if (s.empty()) {
            throw runtime_error("Stack is empty. Cannot retrieve top element.");
        }
        return s.top();
    }

    
    int secondToTop() {
        if (s.size() < 2) {
            throw runtime_error("Stack does not have enough elements to retrieve the second-to-top element.");
        }
        
        // Create a temporary stack to hold the top elements
        int topElement = s.top(); 
        s.pop(); 
        int secondTopElement = s.top(); 
        s.push(topElement); 
        
        return secondTopElement;
    }


};

int main() {
    CustomStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;
    cout << "Second-to-top element: " << stack.secondToTop() << endl; 

    stack.pop();
    cout << "After popping, top element: " << stack.top() << endl;
    cout << "After popping, second-to-top element: " << stack.secondToTop() << endl;

    return 0;
}

