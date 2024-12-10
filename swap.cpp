#include <iostream>
using namespace std;

void swapMaxMin(int arr[], int size) {
    int maxIndex = 0;
    int minIndex = 0;

    
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

   
    int temp = arr[maxIndex];
    arr[maxIndex] = arr[minIndex];
    arr[minIndex] = temp;
}

int main() {
    int size = 5;
    int arr[size];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    
    swapMaxMin(arr, size);

   
    cout << "Array after swapping max and min elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

