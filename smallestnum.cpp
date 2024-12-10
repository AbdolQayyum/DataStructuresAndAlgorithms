#include <iostream>
using namespace std;

void findSmallestNumber() {
    int size = 5;
    int array[size];
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int smallestindex;
    int largestindex;

    cout << "Enter array elements:" << endl;

    for (int i = 0; i < size - 1; i++) {
        cin >> array[i];
    }

    cout << "Array Elements are:" << endl;

    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }

    for (int i = 0; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
            smallestindex = i;
        }
        if (array[i] > largest){
        	largest = array[i];
        	largestindex = i;
		}
        
    }

    cout << "The smallest number in the array is: " << smallest << endl;
    cout << "The largest number in the array is: " << largest << endl;
    
}

