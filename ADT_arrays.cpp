#include <iostream>
using namespace std;

class ListADT {
private:
    int* list;
    int size;
    int capacity;

public:
    // Constructor to initialize the list with a certain capacity
    ListADT(int cap) {
        list = new int[cap];
        size = 0;
        capacity = cap;
    }

    // Insert an element at the end
    void insert_end(int element) {
        if (size == capacity) {
            cout << "List is full" << endl;
        } else {
            list[size] = element;
            size++;
        }
    }

    // Insert an element at the start
    void insert_start(int element) {
        if (size == capacity) {
            cout << "List is full" << endl;
        } else {
            for (int i = size; i > 0; i--) {
                list[i] = list[i - 1];  // Shifting elements to the right
            }
            list[0] = element;
            size++;
        }
    }

    // Insert an element at a specific position
    void insert_at(int element, int position) {
        if (size == capacity) {
            cout << "List is full" << endl;
        } else if (position < 0 || position > size) {
            cout << "Invalid position" << endl;
        } else {
            for (int i = size; i > position; i--) {
                list[i] = list[i - 1];  // Shifting elements to the right
            }
            list[position] = element;
            size++;
        }
    }

    // Delete an element from the start
    void delete_start() {
        if (size == 0) {
            cout << "List is empty" << endl;
        } else {
            for (int i = 0; i < size - 1; i++) {
                list[i] = list[i + 1];  // Shifting elements to the left
            }
            size--;
        }
    }

    // Delete an element from the end
    void delete_end() {
        if (size == 0) {
            cout << "List is empty" << endl;
        } else {
            size--;
        }
    }

    // Delete an element from a specific position
    void delete_at(int position) {
        if (size == 0) {
            cout << "List is empty" << endl;
        } else if (position < 0 || position >= size) {
            cout << "Invalid position" << endl;
        } else {
            for (int i = position; i < size - 1; i++) {
                list[i] = list[i + 1];  // Shifting elements to the left
            }
            size--;
        }
    }

    // Update an element at a specific position
    void update_at(int element, int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position" << endl;
        } else {
            list[position] = element;
        }
    }

    // Search for an element and return its position
    int search(int element) {
        for (int i = 0; i < size; i++) {
            if (list[i] == element) {
                return i;  // Return the index of the element
            }
        }
        return -1;  // Return -1 if element not found
    }

    // Display the list
    void display() {
        if (size == 0) {
            cout << "List is empty" << endl;
        } else {
            for (int i = 0; i < size; i++) {
                cout << list[i] << " ";
            }
            cout << endl;
        }
    }

    // Destructor to free the allocated memory
    ~ListADT() {
        delete[] list;
    }
};

// Main function to test the List ADT
int main() {
    ListADT list(10);  // Create a list with capacity of 10

    // Inserting elements
    list.insert_end(10);
    list.insert_end(20);
    list.insert_start(5);
    list.insert_start(15);
//    list.insert_at(15, 2);

    // Displaying the list
    cout << "List after insertions: ";
    list.display();

    // Deleting elements
    list.delete_start();
    list.delete_at(1);
    list.delete_end();

    // Displaying the list
    cout << "List after deletions: ";
    list.display();

    // Updating an element
    list.update_at(25, 0);

    // Displaying the list
    cout << "List after update: ";
    list.display();

    // Searching for an element
    int index = list.search(25);
    if (index != -1) {
        cout << "Element 25 found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

