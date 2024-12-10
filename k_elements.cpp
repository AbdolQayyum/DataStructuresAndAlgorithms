#include <iostream>
using namespace std;


void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArray(int arr[], int n, int k) {
    

    // Reverse the entire array
    reverseArray(arr, 0, n - 1);

    // Reverse the first K elements
    reverseArray(arr, 0, k - 1);

    //Reverse the remaining elements
    reverseArray(arr, k, n - 1);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; 

    cout << "Original array: ";
    printArray(arr, n); 

    rotateArray(arr, n, k); 

    cout << "Array after rotation: ";
    printArray(arr, n);

    return 0;
}

