#include <iostream>
using namespace std;

#define TABLE_SIZE 10

int h[TABLE_SIZE] = {0}; 

void insert() {
    int key, index, i, hkey;
    cout << "\nEnter a value to insert into hash table: ";
    cin >> key;

    hkey = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;
        if (h[index] == 0) { 
            h[index] = key;
            cout << "Value " << key << " inserted at index " << index << ".\n";
            return;
        }
    }

    cout << "\nElement cannot be inserted. Hash table is full.\n";
}

void search() {
    int key, index, i, hkey;
    cout << "\nEnter the value to search: ";
    cin >> key;

    hkey = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE; 
        if (h[index] == key) {
            cout << "Value " << key << " found at index " << index << ".\n";
            return;
        }
    }

    cout << "\nValue " << key << " is not found in the hash table.\n";
}

void display() {
    cout << "\nElements in the hash table are:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << " -> Value: " << h[i] << "\n";
    }
}

int main() {
    int opt;
    while (true) {
        cout << "\nPress 1. Insert\t 2. Display\t 3. Search\t 4. Exit\n";
        cout << "Enter your choice: ";
        cin >> opt;
        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}

