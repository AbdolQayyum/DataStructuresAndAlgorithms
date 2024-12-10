#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int array[size];
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int smallestIndex;
    int largestIndex;

    cout << "Enter array elements:" << endl;

    
    for (int i = 0; i < size; i++) { 
        cin >> array[i];
    }

    cout << "Array Elements are:" << endl;

    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }

   
    for (int i = 0; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
            smallestIndex = i;
        }
        if (array[i] > largest) {
            largest = array[i];
            largestIndex = i;
        }
    }

    cout << "The smallest number in the array is: " << smallest << " at index " << smallestIndex << endl;
    cout << "The largest number in the array is: " << largest << " at index " << largestIndex << endl;

    return 0;
}

