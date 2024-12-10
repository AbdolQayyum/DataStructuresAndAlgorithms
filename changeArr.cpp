#include <iostream>
using namespace std;

// Function to change the array by taking input values
void changearray(int arr[], int size) {
    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main() {
    const int size = 5;  
    int arr[size];       
    int sumArray[size];  

    
    changearray(arr, size);

  
    for (int i = 0; i < size; i++) {
        sumArray[i] = arr[i] + 10; 
    }

    
    cout << "Values in the new array after addition:" << endl;
    for (int i = 0; i < size; i++) {
        cout << sumArray[i] << " ";
    }
    cout << endl;

    return 0;
}

