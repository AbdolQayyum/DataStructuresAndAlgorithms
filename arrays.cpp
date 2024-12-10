#include <iostream>
using namespace std;

int main() {
    int size = 5; // Array size of 5
    int array[size]; // Declaring the array
    int smallest = INT_MAX; // Initialize smallest to the highest possible value

    cout << "Enter array elements:" << endl;

    // Input array elements
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << "Array Elements are:" << endl;

    // Displaying array elements
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl; // No need to declare a new 'i'
    }

    // Finding the smallest number
    for (int i = 0; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }

    // Display the smallest number
    cout << "The smallest number in the array is: " << smallest << endl;

    return 0;
}

